class Solution:
    def kItemsWithMaximumSum(
        self, numOnes: int, numZeros: int, numNegOnes: int, k: int
    ) -> int:
        return min(k, numOnes) - max(k - numOnes - numZeros, 0)
