def number_base_converter(number: str, from_base: int, to_base: int) -> str:
	digits: str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	for char in number:
		if char not in digits[:from_base]:
			return "ERROR"
	if from_base == to_base:
		return number
	elif from_base == 10:
		return from_decimal(number, to_base, digits)
	elif to_base == 10:
		return to_decimal(number, from_base, digits)
	else:
		decimal: str = to_decimal(number, from_base, digits)
		return from_decimal(decimal, to_base, digits)

def from_decimal(number: str, to_base: int, digits: str) -> str:
	result: str = ""
	decimal_number = int(number)
	while decimal_number > to_base:
		result += digits[decimal_number % to_base]
		decimal_number = decimal_number // to_base
	result += digits[decimal_number % to_base]
	result = result[::-1]
	return result

def to_decimal(number: str, from_base: int, digits: str) -> str:
	result: int = 0
	for i in range(len(number)):
		result += pow(from_base, i) * digits.index(number[len(number) - 1 - i])
	return str(result)

print(number_base_converter("1010", 2, 10))  # Expected: "10"
print(number_base_converter("FF", 16, 10))  # Expected: "255"
print(number_base_converter("255", 10, 16))  # Expected: "FF"
print(number_base_converter("123", 10, 2))  # Expected: "1111011"
print(number_base_converter("Z", 36, 10))  # Expected: "35"
print(number_base_converter("35", 10, 36))  # Expected: "Z"
print(number_base_converter("123", 1, 10))  # Expected: "ERROR"
print(number_base_converter("G", 16, 10))  # Expected: "ERROR"
print(number_base_converter("1111011", 2, 16))  # Expected: "7B"