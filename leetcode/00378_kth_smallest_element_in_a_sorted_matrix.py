class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low, high = matrix[0][0], matrix[-1][-1]
        while low < high:
            mid = (low + high) // 2
            if sum(bisect.bisect(row, mid) for row in matrix) < k:
                low = mid + 1
            else:
                high = mid
        return low