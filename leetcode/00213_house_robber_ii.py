class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        def solve(start: int, end: int) -> int:
            pp, p = 0, 0
            for i in range(start, end):
                pp, p = p, max(pp + nums[i], p)
            return p

        return nums[0] if n == 1 else max(solve(0, n - 1), solve(1, n))
