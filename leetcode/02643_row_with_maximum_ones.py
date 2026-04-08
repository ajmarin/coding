class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        count = row_index = 0
        for i, row in enumerate(mat):
            ones = sum(row)
            if ones > count:
                count = ones
                row_index = i
        return [row_index, count]
