class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        prev, n = 0, len(stones)
        for i in range(n):
            stones[i] += prev
            prev = stones[i]

        ans = stones[-1]
        for i in range(n - 2, 0, -1):
            ans = ans if ans * 2 > stones[i] else stones[i] - ans

        return ans
