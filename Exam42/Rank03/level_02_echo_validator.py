def echo_validator(text: str) -> bool:
	if text == "":
		return False
	text = text.lower().replace(" ", "")
	start: int = 0
	end: int = len(text) - 1
	while start < end:
		if text[start] != text[end]:
			return False
		else:
			start += 1
			end -= 1
	return True

print(echo_validator("racecar"))  # Expected: True
print(echo_validator("A man a plan a canal Panama"))  # Expected: True
print(echo_validator("race a car"))  # Expected: False
print(echo_validator("Was it a car or a cat I saw"))  # Expected: True
print(echo_validator("hello"))  # Expected: False
print(echo_validator("Madam Im Adam"))  # Expected: True
print(echo_validator("madam"))  # Expected: True
print(echo_validator("Able was I ere I saw Elba"))  # Expected: True
print(echo_validator(""))  # Expected: False