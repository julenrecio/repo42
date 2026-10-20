def string_permutation_checker(s1: str, s2: str) -> bool:
	return sorted(s1) == sorted(s2)

print(string_permutation_checker("abc", "bca"))  # Expected: True
print(string_permutation_checker("abc", "def"))  # Expected: False
print(string_permutation_checker("listen", "silent"))  # Expected: True
print(string_permutation_checker("hello", "bello"))  # Expected: False
print(string_permutation_checker("", ""))  # Expected: True
print(string_permutation_checker("a", ""))  # Expected: False
print(string_permutation_checker("Abc", "abc"))  # Expected: False
print(string_permutation_checker("a gentleman","elegant man"))  # Expected: True