def cryptic_sorter(strings: list[str]) -> list[str]:
	i: int = 0
	while i < len(strings) - 1:
		if decide_swap(strings[i], strings[i + 1]):
			tmp: str = strings[i + 1]
			strings[i + 1] = strings[i]
			strings[i] = tmp
			i = 0
		else:
			i += 1
	return strings

def decide_swap(s1: str, s2: str) -> bool:
	if decide_swap_len(s1, s2):
		if len(s1) > len(s2):
			return True
		elif decide_swap_ascii(s1, s2):
			return True
		elif decide_swap_vocals(s1, s2):
			return True
		else:
			return False
	else:
		return False

def decide_swap_len(s1: str, s2: str) -> bool:
	if len(s1) >= len(s2):
		return True
	else:
		return False

def decide_swap_ascii(s1: str, s2: str) -> bool:
	for i in range(len(s1)):
		if s1[i].lower() > s2[i].lower():
			return True
		elif s1[i].lower() < s2[i].lower():
			return False
	return False

def decide_swap_vocals(s1: str, s2: str) -> bool:
	vocals: str = "aeiou"
	s1_vocals: int = 0
	s2_vocals: int = 0
	for i in range(len(s1)):
		if s1[i] in vocals:
			s1_vocals += 1
		if s2[i] in vocals:
			s2_vocals += 1
	if s1_vocals < s2_vocals:
		return True
	else:
		return False

print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))  # Expected: ["cat","dog","apple","banana","elephant"]
print(cryptic_sorter(["aaa","bbb","AAA","BBB"]))  # Expected: ["aaa", "AAA", "bbb", "BBB"]
print(cryptic_sorter(["hello","world","hi","test"]))  # Expected: ["hi","test","hello","world"]
print(cryptic_sorter([]))  # Expected: []
print(cryptic_sorter([""]))  # Expected: [""]