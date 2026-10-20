def whisper_cipher(text: str, shift: int) -> str:
	result: str = ""
	alphabet: str = "abcdefghijklmnopqrstuvwxyz"
	alphabet_mayus: str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	for char in text:
		index: int
		if char in alphabet:
			index = alphabet.index(char) + shift
			if index > 25:
				index %= 26
			result += alphabet[index]
		elif char in alphabet_mayus:
			index = alphabet_mayus.index(char) + shift
			if index > 25:
				index %= 26
			result += alphabet_mayus[index]
		else:
			result += char
	return result

print(whisper_cipher("hello", 3))  # Expected: "khoor"
print(whisper_cipher("Hello World!", 1))  # Expected: "Ifmmp Xpsme!"
print(whisper_cipher("xyz", 3))  # Expected: "abc"
print(whisper_cipher("ABC123def", 5))  # Expected: "FGH123ijk"
print(whisper_cipher("", 10))  # Expected: ""
print(whisper_cipher("abc", -3))  # Expected: "xyz"