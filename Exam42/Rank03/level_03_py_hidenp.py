def hidenp(small: str, big: str) -> bool:
	i: int = 0
	j: int = 0
	while j < len(small) and i < len(big):
		if small[j] == big[i]:
			j += 1
		i += 1
	if len(small) == j:
		return True
	else:
		return False

print(hidenp("abc", "a1b2c3"))  # Expected: True
print(hidenp("ace", "abcde"))  # Expected: True
print(hidenp("aec", "abcde"))  # Expected: False
print(hidenp("", "abc"))  # Expected: True
print(hidenp("abc", "ab"))  # Expected: False
print(hidenp("aaaa", "aaa"))  # Expected: False
print(hidenp("sing","subsequence testing"))  # Expected: True