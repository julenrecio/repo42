def pattern_tracker(text: str) -> int:
	counter: int = 0
	for i in range(len(text) - 1):
		if text[i].isdigit() and text[i + 1].isdigit() and int(text[i]) == int(text[i + 1]) - 1:
			counter += 1
	return counter

print(pattern_tracker("123"))  # Expected: 2
print(pattern_tracker("12a34"))  # Expected: 2
print(pattern_tracker("987654321"))  # Expected: 0
print(pattern_tracker("01234567"))  # Expected: 7
print(pattern_tracker("abc"))  # Expected: 0
print(pattern_tracker("1a2b3c4"))  # Expected: 0
print(pattern_tracker("112233"))  # Expected: 2