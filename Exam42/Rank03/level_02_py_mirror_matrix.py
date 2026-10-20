def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
	for integers in matrix:
		integers.reverse()
	return matrix

print(mirror_matrix([[1,2,3],[4,5,6]]))  # Expected: [[3,2,1],[6,5,4]]
print(mirror_matrix([[1,2],[3,4],[5,6]]))  # Expected: [[2,1],[4,3],[6,5]]
print(mirror_matrix([[7]]))  # Expected: [[7]]
print(mirror_matrix([[1,2,3,4]]))  # Expected: [[4,3,2,1]]
print(mirror_matrix([[-1,-2],[-3,-4]]))  # Expected: [[-2,-1],[-4,-3]]