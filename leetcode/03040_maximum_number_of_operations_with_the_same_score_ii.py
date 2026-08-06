class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        n = len(nums) - 1

        @cache
        def dp(l: int, r: int, g: int) -> int:
            if r - l < 1:
                return 0
            s = -1
            if nums[l] + nums[l + 1] == g:
                s = dp(l + 2, r, g)
            if nums[r] + nums[r - 1] == g:
                cand = dp(l, r - 2, g)
                s = cand if cand > s else s
            if nums[l] + nums[r] == g:
                cand = dp(l + 1, r - 1, g)
                s = cand if cand > s else s
            return 1 + s

        return max(
            dp(0, n, nums[0] + nums[1]),
            dp(0, n, nums[-2] + nums[-1]),
            dp(0, n, nums[0] + nums[-1]),
        )
