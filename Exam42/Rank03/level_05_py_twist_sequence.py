def twist_sequence(arr: list[int], k: int) -> list[int]:
	if len(arr) == 0:
		return arr
	k = k % len(arr)
	new_start: int = len(arr) - k
	result: list[int] = []
	for i in range(k):
		result.append(arr[new_start + i])
	for i in range(new_start):
		result.append(arr[i])
	return result

print(twist_sequence([1,2,3,4,5], 2))  # Expected: [4,5,1,2,3]
print(twist_sequence([1,2,3], 1))  # Expected: [3,1,2]
print(twist_sequence([1,2,3,4], 0))  # Expected: [1,2,3,4]
print(twist_sequence([1,2,3], 5))  # Expected: [2,3,1]
print(twist_sequence([], 3))  # Expected: []