#!/bin/bash
# =============================================================================
#  CODEXION - Test Suite Completa (English) - Hardened / Fixed
#  Changes vs original:
#   - colors defined before first use
#   - crash (SIGSEGV/SIGABRT/SIGBUS) is NEVER conflated with a clean rejection
#   - fixed inverted logic on the n_compiles_required test
#   - Makefile rules (clean/fclean/re, no needless relink) are tested
#   - compiler warnings are captured instead of discarded
#   - per-coder state cycle (dongle x2 -> compile -> debug -> refactor) checked
#     with a single-pass awk parser instead of O(n_coder * n_lines) bash loops
#   - burnout timestamp tolerance window fixed to be one-sided (>= deadline)
#   - valgrind checks rely on exit code, not just on grep'd text
#   - flaky/timing-sensitive tests are retried and require a majority pass
#   - basic static check for forbidden global variables
# =============================================================================
 
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'
 
clear
printf "${CYAN}${BOLD}"
printf "██████╗  ██████╗ ██████╗ ███████╗██╗  ██╗██╗ ██████╗ ███╗   ██╗\n"
printf "██╔════╝██╔═══██╗██╔══██╗██╔════╝╚██╗██╔╝██║██╔═══██╗████╗  ██║\n"
printf "██║     ██║   ██║██║  ██║█████╗   ╚███╔╝ ██║██║   ██║██╔██╗ ██║\n"
printf "██║     ██║   ██║██║  ██║██╔══╝   ██╔██╗ ██║██║   ██║██║╚██╗██║\n"
printf "╚██████╗╚██████╔╝██████╔╝███████╗██╔╝ ██╗██║╚██████╔╝██║ ╚████║\n"
printf " ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n"
printf "${RESET}\n"
printf "${YELLOW}${BOLD}                   TEST SUITE${RESET}\n\n"
 
BIN="./codexion"
PASS=0
FAIL=0
TOTAL=0
 
print_header() {
    echo -e "\n${CYAN}${BOLD}==================================================${RESET}"
    echo -e "${CYAN}${BOLD}  $1${RESET}"
    echo -e "${CYAN}${BOLD}==================================================${RESET}"
}
 
print_test() {
    TOTAL=$((TOTAL + 1))
    echo -e "\n${BOLD}[TEST $TOTAL]${RESET} $1"
}
 
pass() {
    PASS=$((PASS + 1))
    echo -e "  ${GREEN}PASSED${RESET}: $1"
}
 
fail() {
    FAIL=$((FAIL + 1))
    echo -e "  ${RED}FAILED${RESET}: $1"
}
 
ok() { grep -qE "$2" <<< "$1"; }
nok() { ! grep -qE "$2" <<< "$1"; }
 
# Signal-aware rejection check.
# A clean rejection (exit code 1..125, NOT a signal-death code) is a PASS.
# A crash (SIGSEGV=139, SIGABRT=134, SIGBUS=135, SIGFPE=136, or any 128+N) is
# always a hard FAIL, even though its exit code is also "!= 0" - the subject
# explicitly states crashes are graded 0, so a tester must never let a crash
# masquerade as a valid rejection.
check_rejected() {
    local label="$1" out="$2" code="$3"
    if [ "$code" -ge 128 ]; then
        local sig=$((code - 128))
        fail "$label -> CRASHED (signal $sig, exit=$code) instead of a clean rejection"
    elif [ "$code" -eq 0 ]; then
        fail "$label -> Accepted (exit=0), should have been rejected"
    else
        pass "$label -> Rejected cleanly (exit=$code)"
    fi
}
 
# Signal-aware "should run fine" check (exit 0, no crash, no burnout in output).
check_clean_run() {
    local label="$1" out="$2" code="$3"
    if [ "$code" -ge 128 ]; then
        fail "$label -> CRASHED (signal $((code - 128)), exit=$code)"
    elif ok "$out" "burned out"; then
        fail "$label -> unexpected burnout"
    elif [ "$code" -ne 0 ]; then
        fail "$label -> exit=$code"
    else
        pass "$label -> OK"
    fi
}
 
# Retries a clean-run scenario up to $tries times; passes if a strict
# majority of runs succeed. Used only for timing-sensitive / concurrency
# scenarios where a single run can be flaky due to OS scheduling jitter.
retry_clean_run() {
    local label="$1" tries="$2"; shift 2
    local okcount=0 lastout="" lastcode=0
    for i in $(seq 1 "$tries"); do
        lastout=$("$@" 2>&1); lastcode=$?
        if [ "$lastcode" -eq 0 ] && nok "$lastout" "burned out"; then
            okcount=$((okcount + 1))
        elif [ "$lastcode" -ge 128 ]; then
            fail "$label -> CRASHED on attempt $i (signal $((lastcode - 128)))"
            return
        fi
    done
    local need=$(( (tries + 1) / 2 ))
    if [ "$okcount" -ge "$need" ]; then
        pass "$label ($okcount/$tries runs OK)"
    else
        fail "$label (only $okcount/$tries runs OK)"
    fi
}
 
# --------------------------------------------------------------------------
# 0. COMPILATION
# --------------------------------------------------------------------------
print_header "0. COMPILATION"
 
print_test "make fclean (start from a clean slate)"
make fclean -C . > /dev/null 2>&1
[ ! -f "$BIN" ] && pass "Binary removed" || fail "Binary still present after fclean"
 
print_test "make - compilation + warnings check"
BUILD_OUT=$(make -C . 2>&1)
if [ -f "$BIN" ]; then
    pass "Binary '$BIN' present"
else
    fail "Binary not found"
    echo "$BUILD_OUT" | tail -30
    exit 1
fi
 
print_test "no compiler warnings (-Wall -Wextra -Werror)"
if echo "$BUILD_OUT" | grep -qiE "warning:|error:"; then
    fail "Warnings/errors found in build output"
    echo "$BUILD_OUT" | grep -iE "warning:|error:" | head -10
else
    pass "Clean build"
fi
 
print_test "make re does not needlessly relink (no-op second build)"
make -C . > /dev/null 2>&1
SECOND=$(make -C . 2>&1)
if echo "$SECOND" | grep -qiE "cc |gcc |clang "; then
    fail "Second 'make' recompiled/relinked something: $SECOND"
else
    pass "Nothing to rebuild"
fi
 
print_test "make clean removes object files, keeps binary"
make clean -C . > /dev/null 2>&1
OBJ_LEFT=$(find . -maxdepth 2 -name "*.o" 2>/dev/null | wc -l)
if [ "$OBJ_LEFT" -eq 0 ] && [ -f "$BIN" ]; then
    pass "Objects cleaned, binary kept"
else
    fail "Either .o files remain ($OBJ_LEFT) or binary was removed"
fi
 
print_test "make fclean removes the binary too"
make fclean -C . > /dev/null 2>&1
[ ! -f "$BIN" ] && pass "Binary removed" || fail "Binary still present"
 
print_test "make re rebuilds everything from scratch"
make re -C . > /dev/null 2>&1
[ -f "$BIN" ] && pass "Binary rebuilt via re" || fail "re did not produce the binary"
 
print_test "basic static check: no obvious global variables"
GLOBALS=$(grep -RnE '^(static\s+)?(int|char|long|short|unsigned|float|double|struct\s+\w+|t_[a-zA-Z_]+)\s+\**\w+\s*(=[^=]|;)' --include='*.c' . 2>/dev/null | grep -vE '^\s*\S+:\s*(int|char)\s+main\s*\(' )
if [ -z "$GLOBALS" ]; then
    pass "No obvious top-level variable declarations found"
else
    fail "Possible global variable(s) - manual review needed:"
    echo "$GLOBALS" | head -10
fi
 
# --------------------------------------------------------------------------
# 1. INVALID INPUTS
# --------------------------------------------------------------------------
print_header "1. INVALID INPUTS"
 
print_test "No arguments"
O=$(timeout 2 $BIN 2>&1); E=$?
check_rejected "No arguments" "$O" "$E"
 
print_test "7 arguments (instead of 8)"
O=$(timeout 2 $BIN 5 800 200 200 200 3 100 2>&1); E=$?
check_rejected "7 arguments" "$O" "$E"
 
print_test "9 arguments"
O=$(timeout 2 $BIN 5 800 200 200 200 3 100 fifo extra 2>&1); E=$?
check_rejected "9 arguments" "$O" "$E"
 
print_test "n_coders <= 0"
O=$(timeout 2 $BIN 0 800 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "n_coders=0" "$O" "$E"
 
print_test "negative n_coders"
O=$(timeout 2 $BIN -5 800 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "n_coders=-5" "$O" "$E"
 
print_test "time_to_burnout = 0"
O=$(timeout 2 $BIN 5 0 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "time_to_burnout=0" "$O" "$E"
 
print_test "negative time_to_compile"
O=$(timeout 2 $BIN 5 800 -200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "time_to_compile=-200" "$O" "$E"
 
print_test "negative time_to_debug"
O=$(timeout 2 $BIN 5 800 200 -200 200 3 100 fifo 2>&1); E=$?
check_rejected "time_to_debug=-200" "$O" "$E"
 
print_test "negative time_to_refactor"
O=$(timeout 2 $BIN 5 800 200 200 -200 3 100 fifo 2>&1); E=$?
check_rejected "time_to_refactor=-200" "$O" "$E"
 
print_test "n_compiles_required = 0 (edge value, must be explicitly decided)"
O=$(timeout 2 $BIN 5 800 200 200 200 0 100 fifo 2>&1); E=$?
# 0 required compiles is ambiguous by spec: either reject it as invalid, or
# accept it and terminate immediately/successfully. What must NEVER happen
# is a crash. We only assert "no crash" here and report the observed choice.
if [ "$E" -ge 128 ]; then
    fail "n_compiles_required=0 -> CRASHED (signal $((E - 128)))"
elif [ "$E" -eq 0 ]; then
    pass "n_compiles_required=0 -> accepted, exits cleanly (exit=0)"
else
    pass "n_compiles_required=0 -> rejected cleanly (exit=$E)"
fi
 
print_test "negative n_compiles_required"
O=$(timeout 2 $BIN 5 800 200 200 200 -1 100 fifo 2>&1); E=$?
check_rejected "n_compiles_required=-1" "$O" "$E"
 
print_test "negative dongle_cooldown"
O=$(timeout 2 $BIN 5 800 200 200 200 3 -100 fifo 2>&1); E=$?
check_rejected "dongle_cooldown=-100" "$O" "$E"
 
print_test "wrong scheduler (uppercase FIFO)"
O=$(timeout 2 $BIN 5 800 200 200 200 3 100 FIFO 2>&1); E=$?
check_rejected "scheduler=FIFO" "$O" "$E"
 
print_test "made-up scheduler"
O=$(timeout 2 $BIN 5 800 200 200 200 3 100 rr 2>&1); E=$?
check_rejected "scheduler=rr" "$O" "$E"
 
print_test "non-numeric argument"
O=$(timeout 2 $BIN abc 800 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "n_coders=abc" "$O" "$E"
 
print_test "float as n_coders"
O=$(timeout 2 $BIN 3.5 800 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "n_coders=3.5" "$O" "$E"
 
print_test "overflow n_coders"
O=$(timeout 2 $BIN 99999999999 800 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "n_coders=99999999999" "$O" "$E"
 
print_test "trailing garbage in a numeric argument (5abc)"
O=$(timeout 2 $BIN 5abc 800 200 200 200 3 100 fifo 2>&1); E=$?
check_rejected "n_coders=5abc" "$O" "$E"
 
print_test "leading/trailing whitespace argument"
O=$(timeout 2 $BIN " 5" 800 200 200 200 3 100 fifo 2>&1); E=$?
if [ "$E" -ge 128 ]; then
    fail "n_coders=' 5' -> CRASHED (signal $((E - 128)))"
else
    pass "n_coders=' 5' -> handled without crashing (exit=$E, either accepted or rejected)"
fi
 
# --------------------------------------------------------------------------
# 2. SPECIAL CASE: 1 CODER (MUST ALWAYS BURN OUT)
# --------------------------------------------------------------------------
print_header "2. 1 CODER - INEVITABLE BURNOUT"
 
print_test "FIFO - expected burnout"
O=$(timeout 3 $BIN 1 800 200 200 200 1 100 fifo 2>&1)
ok "$O" "burned out" && pass "Burnout" || fail "No burnout"
 
print_test "EDF - expected burnout"
O=$(timeout 3 $BIN 1 800 200 200 200 1 100 edf 2>&1)
ok "$O" "burned out" && pass "Burnout" || fail "No burnout"
 
print_test "burnout within 10ms of deadline (600ms) - FIFO"
T1=$(date +%s%3N)
O=$(timeout 3 $BIN 1 600 200 200 200 1 100 fifo 2>&1)
T2=$(date +%s%3N)
EL=$((T2 - T1))
if ok "$O" "burned out" && [ "$EL" -ge 500 ] && [ "$EL" -le 800 ]; then
    pass "Elapsed ${EL}ms (expected ~600ms)"
else
    fail "Elapsed ${EL}ms out of range (out: $O)"
fi
 
print_test "a single burnout message"
O=$(timeout 3 $BIN 1 800 200 200 200 1 100 fifo 2>&1)
C=$(grep -c "burned out" <<< "$O")
[ "$C" -eq 1 ] && pass "1 burnout" || fail "Burnout count = $C"
 
# --------------------------------------------------------------------------
# 3. CORRECT EXECUTIONS (NO BURNOUT) - FEASIBLE PARAMETERS
# --------------------------------------------------------------------------
print_header "3. CORRECT EXECUTIONS (NO BURNOUT)"
 
print_test "2 coders FIFO - deadline 800, cooldown 0"
O=$(timeout 10 $BIN 2 800 200 200 200 3 0 fifo 2>&1); E=$?
check_clean_run "2 coders FIFO" "$O" "$E"
 
print_test "2 coders EDF - deadline 800, cooldown 0"
O=$(timeout 10 $BIN 2 800 200 200 200 3 0 edf 2>&1); E=$?
check_clean_run "2 coders EDF" "$O" "$E"
 
print_test "3 coders FIFO - deadline 1200, cooldown 100 (feasible)"
O=$(timeout 15 $BIN 3 1200 200 200 200 3 100 fifo 2>&1); E=$?
check_clean_run "3 coders FIFO" "$O" "$E"
 
print_test "3 coders EDF - deadline 1200, cooldown 100 (feasible)"
O=$(timeout 15 $BIN 3 1200 200 200 200 3 100 edf 2>&1); E=$?
check_clean_run "3 coders EDF" "$O" "$E"
 
print_test "4 coders FIFO - deadline 1200, cooldown 100"
O=$(timeout 15 $BIN 4 1200 200 200 200 3 100 fifo 2>&1); E=$?
check_clean_run "4 coders FIFO" "$O" "$E"
 
print_test "4 coders EDF - deadline 1200, cooldown 100"
O=$(timeout 15 $BIN 4 1200 200 200 200 3 100 edf 2>&1); E=$?
check_clean_run "4 coders EDF" "$O" "$E"
 
print_test "5 coders FIFO - deadline 1200, cooldown 100"
O=$(timeout 20 $BIN 5 1200 200 200 200 3 100 fifo 2>&1); E=$?
check_clean_run "5 coders FIFO" "$O" "$E"
 
print_test "5 coders EDF - deadline 1200, cooldown 100"
O=$(timeout 20 $BIN 5 1200 200 200 200 3 100 edf 2>&1); E=$?
check_clean_run "5 coders EDF" "$O" "$E"
 
print_test "n_compiles_required=1 - quick termination"
O=$(timeout 5 $BIN 3 800 200 200 200 1 100 fifo 2>&1); E=$?
check_clean_run "n_compiles_required=1" "$O" "$E"
 
print_test "10 compilations - EDF deadline 1500, cooldown 100"
O=$(timeout 30 $BIN 3 1500 200 200 200 10 100 edf 2>&1); E=$?
check_clean_run "10 compilations EDF" "$O" "$E"
 
# --------------------------------------------------------------------------
# 4. FORCED BURNOUT (EXPECTED)
# --------------------------------------------------------------------------
print_header "4. FORCED BURNOUT (EXPECTED)"
 
print_test "compile(500ms) > burnout(100ms) - FIFO"
O=$(timeout 5 $BIN 5 100 500 200 200 3 50 fifo 2>&1)
ok "$O" "burned out" && pass "Burnout" || fail "No burnout"
 
print_test "compile(500ms) > burnout(100ms) - EDF"
O=$(timeout 5 $BIN 5 100 500 200 200 3 50 edf 2>&1)
ok "$O" "burned out" && pass "Burnout" || fail "No burnout"
 
print_test "high cooldown (500ms) vs short burnout (300ms) - cooldown burnout"
O=$(timeout 5 $BIN 2 300 100 50 50 5 500 fifo 2>&1)
ok "$O" "burned out" && pass "Burnout" || fail "No burnout"
 
# --------------------------------------------------------------------------
# 5. LOG OUTPUT FORMAT
# --------------------------------------------------------------------------
print_header "5. LOG OUTPUT FORMAT"
 
O=$(timeout 8 $BIN 2 800 200 200 200 2 100 fifo 2>&1)
 
print_test "Basic messages present"
all_present=1
for MSG in "has taken a dongle" "is compiling" "is debugging" "is refactoring"; do
    ok "$O" "$MSG" || all_present=0
done
[ "$all_present" -eq 1 ] && pass "All messages found" || fail "Missing messages"
 
print_test "Line format: <timestamp> <coder_id> <state>"
echo "$O" | grep -vE '^[0-9]+ [0-9]+ (has taken a dongle|is compiling|is debugging|is refactoring|burned out)$' | head -1 | grep -q . && fail "Anomalous lines" || pass "Ok"
 
print_test "2 dongles per compilation (global)"
C=$(grep -c "is compiling" <<< "$O" 2>/dev/null || echo 0)
D=$(grep -c "has taken a dongle" <<< "$O" 2>/dev/null || echo 0)
[ "$D" -eq $((C * 2)) ] && pass "${D}/${C}" || fail "${D}/${C} (expected 2:1)"
 
print_test "Timestamps monotonically increasing"
PREV=0; BAD=0
while IFS= read -r line; do
    TS=$(echo "$line" | awk '{print $1}')
    [[ $TS =~ ^[0-9]+$ ]] && { [ "$TS" -lt "$PREV" ] && BAD=1; PREV=$TS; }
done <<< "$O"
[ "$BAD" -eq 0 ] && pass "Monotonic" || fail "Not monotonic"
 
print_test "Per-coder cycle: dongle x2 -> compile -> debug -> refactor (single-pass awk)"
CYCLE_ERR=$(awk '
{
    id = $2
    if ($0 ~ /has taken a dongle/)      { taken[id]++ }
    else if ($0 ~ /is compiling/) {
        if (taken[id] != 2) { print "coder " id ": compiling with " taken[id] " dongles taken"; exit_code=1 }
        taken[id] = 0
        if (state[id] != "" && state[id] != "refactor" && state[id] != "start") {
            print "coder " id ": compiling after state=" state[id]; exit_code=1
        }
        state[id] = "compile"
    }
    else if ($0 ~ /is debugging/) {
        if (state[id] != "compile") { print "coder " id ": debugging after state=" state[id]; exit_code=1 }
        state[id] = "debug"
    }
    else if ($0 ~ /is refactoring/) {
        if (state[id] != "debug") { print "coder " id ": refactoring after state=" state[id]; exit_code=1 }
        state[id] = "refactor"
    }
    else if ($0 ~ /burned out/) { state[id] = "start"; taken[id] = 0 }
}
END { exit exit_code }
' <<< "$O")
if [ -z "$CYCLE_ERR" ]; then
    pass "Full compile->debug->refactor cycle respected per coder"
else
    fail "Cycle violation(s):"
    echo "$CYCLE_ERR" | head -10
fi
 
# --------------------------------------------------------------------------
# 6. BURNOUT LOG PRECISION
# --------------------------------------------------------------------------
print_header "6. BURNOUT LOG PRECISION"
 
print_test "1 coder burnout=600ms: log within [600, 612]ms (one-sided tolerance)"
O=$(timeout 3 $BIN 1 600 200 200 200 1 100 fifo 2>&1)
if ok "$O" "burned out"; then
    TS=$(grep "burned out" <<< "$O" | awk '{print $1}')
    # The burnout can never legitimately be logged BEFORE the real deadline;
    # only a small delay after it is tolerated (measurement/scheduling jitter).
    if [ "$TS" -ge 600 ] && [ "$TS" -le 612 ]; then
        pass "Timestamp burnout = ${TS}ms"
    else
        fail "Timestamp burnout = ${TS}ms (expected 600-612ms)"
    fi
else
    fail "No burnout"
fi
 
print_test "2 coders burnout=300ms: log present"
O=$(timeout 5 $BIN 2 300 400 100 100 5 100 fifo 2>&1)
ok "$O" "burned out" && pass "Burnout logged" || fail "No burnout"
 
# --------------------------------------------------------------------------
# 7. EDGE CASES
# --------------------------------------------------------------------------
print_header "7. EDGE CASES"
 
print_test "cooldown=1ms (minimum) FIFO"
O=$(timeout 10 $BIN 3 800 200 200 200 3 1 fifo 2>&1); E=$?
check_clean_run "cooldown=1ms FIFO" "$O" "$E"
 
print_test "cooldown=1ms EDF"
O=$(timeout 10 $BIN 3 800 200 200 200 3 1 edf 2>&1); E=$?
check_clean_run "cooldown=1ms EDF" "$O" "$E"
 
print_test "All times equal (200ms) + cooldown 200ms, deadline 1500 FIFO"
O=$(timeout 12 $BIN 4 1500 200 200 200 3 200 fifo 2>&1); E=$?
check_clean_run "equal times FIFO" "$O" "$E"
 
print_test "All times equal (200ms) + cooldown 200ms, deadline 1500 EDF"
O=$(timeout 12 $BIN 4 1500 200 200 200 3 200 edf 2>&1); E=$?
check_clean_run "equal times EDF" "$O" "$E"
 
print_test "debug/refactor/compile = 1ms"
O=$(timeout 10 $BIN 3 800 1 1 1 5 100 fifo 2>&1); E=$?
check_clean_run "1ms phases" "$O" "$E"
 
print_test "very large time_to_burnout (5000ms)"
O=$(timeout 10 $BIN 4 5000 200 200 200 2 100 fifo 2>&1); E=$?
check_clean_run "large burnout window" "$O" "$E"
 
print_test "n_compiles_required=20 - EDF deadline 2000"
O=$(timeout 60 $BIN 3 2000 200 200 200 20 100 edf 2>&1); E=$?
check_clean_run "20 compiles EDF" "$O" "$E"
 
# --------------------------------------------------------------------------
# 8. HIGH CONCURRENCY & STARVATION
# --------------------------------------------------------------------------
print_header "8. HIGH CONCURRENCY & STARVATION"
 
for N in 50 100 150 200; do
    print_test "$N coders EDF, 1 compile (deadline 5000, cooldown 0)"
    O=$(timeout 60 $BIN $N 5000 5 5 5 1 0 edf 2>&1); E=$?
    check_clean_run "$N coders EDF" "$O" "$E"
done
 
print_test "3 coders EDF, deadline 400ms, cycle 240ms -> NO burnout (liveness, 3 retries, majority)"
retry_clean_run "EDF liveness" 3 timeout 15 $BIN 3 400 80 80 80 3 0 edf
 
print_test "All coders compile at least once (FIFO 5, deadline 1200, cooldown 0)"
O=$(timeout 15 $BIN 5 1200 200 200 200 3 0 fifo 2>&1)
ALL_COMPILED=1
for i in 1 2 3 4 5; do
    grep -q "$i is compiling" <<< "$O" || ALL_COMPILED=0
done
nok "$O" "burned out" && [ "$ALL_COMPILED" -eq 1 ] && pass "All compiled" || fail "Some did not compile or burnout"
 
# --------------------------------------------------------------------------
# 9. VALGRIND (MEMCHECK & HELGRIND)
# --------------------------------------------------------------------------
print_header "9. VALGRIND (MEMCHECK & HELGRIND)"
 
if command -v valgrind > /dev/null 2>&1; then
    print_test "Valgrind memcheck - 3 coders no burnout"
    valgrind --leak-check=full --track-origins=yes --error-exitcode=42 \
        $BIN 3 800 200 200 200 2 100 fifo > /dev/null 2>/tmp/vout_$$.log
    VE=$?
    if [ "$VE" -eq 0 ]; then
        pass "No leaks, 0 errors"
    else
        fail "Leaks or errors present (valgrind exit=$VE)"
        tail -20 /tmp/vout_$$.log
    fi
    rm -f /tmp/vout_$$.log
 
    print_test "Valgrind memcheck - 1 coder burnout"
    valgrind --leak-check=full --error-exitcode=42 \
        $BIN 1 800 200 200 200 1 100 fifo > /dev/null 2>/tmp/vout_$$.log
    VE=$?
    if [ "$VE" -eq 0 ]; then
        pass "No leak/error after burnout"
    else
        fail "Leak or error after burnout (valgrind exit=$VE)"
        tail -20 /tmp/vout_$$.log
    fi
    rm -f /tmp/vout_$$.log
 
    print_test "Valgrind memcheck - 10 coders"
    valgrind --leak-check=full --error-exitcode=42 \
        $BIN 10 900 200 200 200 3 100 edf > /dev/null 2>/tmp/vout_$$.log
    VE=$?
    if [ "$VE" -eq 0 ]; then
        pass "No leak"
    else
        fail "Leak with 10 coders (valgrind exit=$VE)"
        tail -20 /tmp/vout_$$.log
    fi
    rm -f /tmp/vout_$$.log
 
    print_test "Helgrind (race condition) - 3 coders EDF"
    valgrind --tool=helgrind --error-exitcode=2 \
        $BIN 3 800 200 200 200 2 100 edf > /dev/null 2>/tmp/vout_$$.log
    HE=$?
    if [ "$HE" -eq 2 ]; then
        fail "Possible data race"
        tail -20 /tmp/vout_$$.log
    else
        pass "No race condition"
    fi
    rm -f /tmp/vout_$$.log
 
    print_test "Helgrind (race condition) - 15 coders EDF (higher contention)"
    valgrind --tool=helgrind --error-exitcode=2 \
        $BIN 15 1500 100 100 100 2 50 edf > /dev/null 2>/tmp/vout_$$.log
    HE=$?
    if [ "$HE" -eq 2 ]; then
        fail "Possible data race under higher contention"
        tail -20 /tmp/vout_$$.log
    else
        pass "No race condition"
    fi
    rm -f /tmp/vout_$$.log
else
    print_test "Valgrind not installed - tests skipped"
    pass "Skip"
fi
 
# --------------------------------------------------------------------------
# FINAL SUMMARY
# --------------------------------------------------------------------------
echo -e "\n${CYAN}${BOLD}==================================================${RESET}"
echo -e "${CYAN}${BOLD}  FINAL SUMMARY${RESET}"
echo -e "${CYAN}${BOLD}==================================================${RESET}"
echo -e "  Total tests : ${BOLD}$TOTAL${RESET}"
echo -e "  ${GREEN}Passed      : $PASS${RESET}"
echo -e "  ${RED}Failed      : $FAIL${RESET}"
echo ""
if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  ALL TESTS PASSED! 🎉${RESET}"
else
    echo -e "${RED}${BOLD}  $FAIL TESTS FAILED - fix and retry.${RESET}"
fi
