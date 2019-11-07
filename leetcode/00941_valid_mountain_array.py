class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        increasing = A[0] < A[1]
        decreasing = A[-2] > A[-1]
        if not increasing or not decreasing:
            return False
        i, n = 1, len(A)
        while i < n and A[i] > A[i - 1]:
            i += 1
        while i < n and A[i] < A[i - 1]:
            i += 1
        return i == n