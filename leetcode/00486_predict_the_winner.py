class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        if ~len(nums) & 1:
            return True

        @cache
        def dp(i: int, j: int) -> int:
            if i == j:
                return nums[i]
            return max(nums[i] - dp(i + 1, j), nums[j] - dp(i, j - 1))

        return dp(0, len(nums) - 1) >= 0
