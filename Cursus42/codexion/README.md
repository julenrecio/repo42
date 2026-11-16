*This project has been created as part of the 42 curriculum by jrecio-t.*

# Codexion

## Description

**Codexion** is a concurrency and resource-synchronization simulation written in C using POSIX threads (`pthread`). Inspired by the classic Dining Philosophers problem, the project models a circular co-working hub where multiple coders compete for scarce USB dongles to compile quantum code before running out of time and burning out.

Each coder is represented by an independent thread that cycles through acquiring two adjacent USB dongles, compiling, debugging, and refactoring. To succeed, the simulation must coordinate access to shared hardware resources without deadlocks, enforce mandatory dongle cooldown periods, arbitrate contention using either **FIFO** (First In, First Out) or **EDF** (Earliest Deadline First) scheduling policies, and detect burnouts within a strict 10 ms precision window.

## Instructions

### Compilation

The project includes a `Makefile` at the root of the repository that compiles all source files inside `coders/` using `cc` with `-Wall -Wextra -Werror -pthread`.

* **Build the executable:**

  ```
  make
  
  ```

* **Remove object files:**

  ```
  make clean
  
  ```

* **Remove object files and the binary:**

  ```
  make fclean
  
  ```

* **Recompile from scratch:**

  ```
  make re
  
  ```

### Execution

Run the program with all 8 mandatory arguments:

```
./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <scheduler>

```

#### Parameters

1. `number_of_coders`: Number of coders and total USB dongles available (`> 0`).

2. `time_to_burnout`: Maximum time in milliseconds a coder can go without starting a compilation before burning out (`> 0`).

3. `time_to_compile`: Duration in milliseconds of the compiling phase while holding two dongles (`> 0`).

4. `time_to_debug`: Duration in milliseconds of the debugging phase (`> 0`).

5. `time_to_refactor`: Duration in milliseconds of the refactoring phase (`> 0`).

6. `number_of_compiles_required`: Target number of compilations per coder for a successful simulation (`> 0`).

7. `dongle_cooldown`: Cooldown period in milliseconds during which a released dongle cannot be re-acquired (`>= 0`).

8. `scheduler`: Arbitration policy for contested dongles (`fifo` or `edf`).

#### Usage Examples

* **Successful simulation with 4 coders using EDF scheduling:**

  ```
  ./codexion 4 1200 200 200 200 3 100 edf
  
  ```

* **Single coder edge case (inevitable burnout due to only 1 dongle available):**

  ```
  ./codexion 1 800 200 200 200 1 100 fifo
  
  ```

## Blocking Cases Handled

### 1. Deadlock Prevention (Coffman's Conditions)

A deadlock occurs when all four Coffman conditions hold simultaneously: *Mutual Exclusion*, *Hold and Wait*, *No Preemption*, and *Circular Wait*. Since USB dongles cannot be shared (*Mutual Exclusion*) or forcibly taken (*No Preemption*), and a coder must hold one dongle while waiting for the second (*Hold and Wait*), this implementation breaks **Circular Wait** by imposing a strict global resource hierarchy.

In `get_dongle_ids()` (`coders/dongles.c`), every coder computes their left (`coder->id - 1`) and right (`coder->id % number_of_coders`) dongle indices and sorts them in ascending order (`ids[0] < ids[1]`). Consequently, all coders—including the last coder sitting next to coder `1`—always acquire the lower-indexed dongle first and the higher-indexed dongle second, making circular dependency cycles impossible.

### 2. Starvation Prevention & Fair Arbitration

Contention for dongles is managed through a custom priority queue (`coders/queue.c`) attached to each dongle:

* **FIFO (`fifo`):** Requests are ordered strictly by arrival timestamp (`request_time`), ensuring bounded waiting times in arrival order.

* **EDF (`edf`):** Requests are ordered by each coder's burnout deadline (`last_compile_time + time_to_burnout`), with `request_time` used as a tie-breaker. Coders closest to burning out are prioritized first, guaranteeing liveness under feasible timing parameters.

### 3. Dongle Cooldown Handling

When a coder finishes compiling and calls `release_dongle()`, the dongle is marked unavailable (`available = false`), flagged as `cooling_down = true`, and assigned an expiration timestamp (`cooldown_at = now + dongle_cooldown`). Waiting threads do not busy-wait; instead, `handle_cooldown()` puts them to sleep via `pthread_cond_timedwait()` until the exact `cooldown_at` deadline expires, after which the dongle transitions back to `available = true` and broadcasts to waiting threads.

### 4. Precise Burnout Detection & Clean Termination

* **1 ms Monitor Polling:** A dedicated monitor thread (`monitor_routine()` in `coders/monitor.c`) checks every coder's elapsed time since `last_compile_time` every `1000` microseconds (`1 ms`), ensuring burnout events are detected and logged well within the 10 ms requirement.

* **Single-Coder Edge Case:** When `number_of_coders == 1`, `ids[0]` and `ids[1]` resolve to dongle `0`. After acquiring dongle `0`, the coder queues a second request for the same unavailable dongle and blocks on `pthread_cond_wait()` until the monitor triggers burnout and wakes all condition variables.

* **Interruptible Sleeps & Unblocking:** Long compile, debug, and refactor durations are split into `500` microsecond slices in `smart_sleep()` (`coders/actions.c`), checking `simulation_ended` on every iteration. When the simulation ends, `wake_all_dongles()` broadcasts on every dongle's condition variable so blocked coders immediately unlink their pending requests (`remove_request()`) and exit without memory leaks.

### 5. Log Serialization

All log output is serialized so lines never interleave and no status message is ever printed after a `burned out` event.

## Thread Synchronization Mechanisms

### Primitives Used

* **Per-Dongle Mutex (`dongle->mutex`, `pthread_mutex_t`):** Protects each dongle's internal state (`available`, `cooling_down`, `cooldown_at`) and its priority `queue`.

* **Per-Dongle Condition Variable (`dongle->cond`, `pthread_cond_t`):** Coordinates threads waiting either for a dongle to become available (`pthread_cond_wait`) or for its cooldown timer to expire (`pthread_cond_timedwait`).

* **Global Simulation Mutex (`sim->global_mutex`, `pthread_mutex_t`):** Protects shared simulation and coder state (`simulation_ended`, `compile_count`, and `last_compile_time`).

* **Output Mutex (`sim->print_mutex`, `pthread_mutex_t`):** Serializes calls to `fprintf(stdout, ...)` so concurrent log lines never overlap.

### Lock Hierarchy & Race Condition Prevention

To prevent lock-order inversions between threads, a strict locking hierarchy is enforced across the codebase:

1. `dongle->mutex` (acquired first when manipulating a dongle's queue or state)

2. `sim->global_mutex` (acquired to inspect/update simulation flags or coder timestamps)

3. `sim->print_mutex` (acquired innermost, only while holding `global_mutex` after verifying `!simulation_ended`)

For example, in `compile()` (`coders/actions.c`), `coder->last_compile_time` is updated atomically under `global_mutex` at the exact moment `"is compiling"` is logged. This prevents a race condition where the monitor thread could evaluate a stale `last_compile_time` and falsely declare a burnout right as a coder starts compiling.

### Coder–Monitor Communication

Coders and the monitor communicate exclusively through mutex-protected state and condition variable broadcasts:

* **Progress Tracking:** Coders increment `compile_count` under `global_mutex` after each compilation. The monitor reads `compile_count` and `last_compile_time` under `global_mutex` via `check_monitor_conditions()`.

* **Termination Broadcast:** Once `all_coders_finished()` is true or a burnout occurs, `end_simulation()` locks `global_mutex`, sets `simulation_ended = true`, prints the final burnout log (if applicable) under `print_mutex`, unlocks `global_mutex`, and invokes `wake_all_dongles()`. Every waiting coder wakes up from `pthread_cond_wait()` or `pthread_cond_timedwait()`, detects `check_vars(coder, false) != 0`, cleans up its queue node, and joins cleanly in `wait_threads_end()`.

## Resources

### Technical References

* **POSIX Threads Programming:** *IEEE Std 1003.1 (POSIX.1-2017) — Threads (`pthread.h`)* and Linux `man` pages (`pthread_create(3)`, `pthread_mutex_lock(3)`, `pthread_cond_wait(3)`, `pthread_cond_timedwait(3)`).

* **Deadlock with Mutex Locks:** [TutorialsPoint — Deadlock with Mutex Locks](https://www.tutorialspoint.com/article/deadlock-with-mutex-locks)

* **Condition Variables (`wait` / `signal`):** [GeeksforGeeks — Condition Wait and Signal in Multi-Threading](https://www.geeksforgeeks.org/linux-unix/condition-wait-signal-multi-threading/)

### AI Usage

AI tools were used as a learning and debugging assistant during development in accordance with the 42 AI guidelines:

* **Concurrency & Edge-Case Review:** Used to analyze potential race conditions, verify lock-ordering hierarchies across `dongle->mutex`, `global_mutex`, and `print_mutex`, and identify edge cases such as queue cleanup on early simulation termination and interruptible sleeps during long action phases.

* **Testing & Verification:** Used to design stress-test scenarios (high coder counts, tight burnout deadlines, Valgrind/Helgrind memory and data-race checks).

* **Documentation:** Used to structure and proofread this `README.md` file. All core architecture, C implementation, data structures, and synchronization logic were written, tested, and verified directly by the author.