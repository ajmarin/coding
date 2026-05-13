class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        diff = [0] * (limit + 1) * 2
        for i in range(n >> 1):
            a, b = nums[i], nums[~i]
            if a > b:
                a, b = b, a
            diff[2] += 2
            diff[a + 1] -= 1
            diff[a + b] -= 1
            diff[a + b + 1] += 1
            diff[b + limit + 1] += 1

        ans, prefix = n, 0
        for i in range(2, len(diff)):
            prefix += diff[i]
            ans = ans if ans < prefix else prefix
        return ans
