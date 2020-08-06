class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            i = abs(n) - 1
            nums[i] = -nums[i]
            if nums[i] > 0:
                ans.append(i + 1)
        return ans