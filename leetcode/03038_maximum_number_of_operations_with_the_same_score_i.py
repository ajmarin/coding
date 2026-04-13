class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        score = nums[0] + nums[1]
        i, n = 3, len(nums)
        while i < n:
            if nums[i] + nums[i - 1] != score:
                break
            i += 2
        return i // 2
