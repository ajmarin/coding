class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        L = len(A)
        inc = all(A[i] >= A[i - 1] for i in range(1, L))
        dec = all(A[i] <= A[i - 1] for i in range(1, L))
        return inc or dec