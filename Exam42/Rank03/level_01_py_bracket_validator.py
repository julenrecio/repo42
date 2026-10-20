def bracket_validator(s: str) -> bool:
	stack: list[str] = []
	pairs: dict[str, str] = {']': '[', ')': '(', '}': '{'}
	for char in s:
		if char in pairs.values():
			stack.append(char)
		elif char in pairs:
			if len(stack) != 0 and pairs[char] != stack.pop():
				return False
	if len(stack) == 0:
		return True
	else:
		return False

print(bracket_validator("()"))  # Expected: True
print(bracket_validator("()[]{}"))  # Expected: True
print(bracket_validator("(]"))  # Expected: False
print(bracket_validator("([)]"))  # Expected: False
print(bracket_validator("{[]}"))  # Expected: True
print(bracket_validator("hello(world)"))  # Expected: True
print(bracket_validator("((())"))  # Expected: False
print(bracket_validator(""))  # Expected: True