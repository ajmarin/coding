class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        left, right = 0, 0
        while right < len(nums):
            if nums[right] != nums[left]:
                nums[left + 1] = nums[right]
                left += 1
            right += 1
        return left + 1