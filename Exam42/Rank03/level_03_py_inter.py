def inter(s1: str, s2: str) -> str:
	both: str = ""
	for c1 in s1:
		if (c1 in s2) and c1 not in both:
			both += c1
	return both

print(inter("hello", "world"))  # Expected: "lo"
print(inter("banana", "band"))  # Expected: "ban"
print(inter("abcabc", "bc"))  # Expected: "bc"
print(inter("abc", "xyz"))  # Expected: ""
print(inter("", "abc"))  # Expected: ""