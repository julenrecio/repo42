def string_sculptor(text: str) -> str:
	result: str = ""
	i: int = 0
	for char in text:
		if char.isalpha():
			if i % 2 == 1:
				result += char.upper()
			else:
				result += char.lower()
			i += 1
		else:
			result += char
	return result

print(string_sculptor("hello"))  # Expected: "hElLo"
print(string_sculptor("Hello World"))  # Expected: "hElLo WoRlD"
print(string_sculptor("   hello   "))  # Expected: "   hElLo   "
print(string_sculptor("abc123def"))  # Expected: "aBc123DeF"
print(string_sculptor("Python3.9!"))  # Expected: "pYtHoN3.9!"
print(string_sculptor(""))  # Expected: ""