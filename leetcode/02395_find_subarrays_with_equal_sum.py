class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        seen = set()
        prev = nums[0]
        for i in range(1, len(nums)):
            total = nums[i] + prev
            if total in seen:
                return True
            seen.add(total)
            prev = nums[i]
        return False
