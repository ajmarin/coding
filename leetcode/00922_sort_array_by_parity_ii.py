class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        odd = 1
        for even in range(0, len(A), 2):
            if A[even] & 1:
                while A[odd] & 1: odd += 2
                A[even], A[odd] = A[odd], A[even]
            even += 2
        return A