class Solution:
    def numTrees(self, n: int) -> int:
        ans = 1
        num = 3
        den = 3
        for _ in range(1, n):
            ans = (ans * 2 * num) // den
            num += 2
            den += 1
        return ans

