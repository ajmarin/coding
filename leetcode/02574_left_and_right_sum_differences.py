class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        left, right = 0, sum(nums)
        ans = []
        for n in nums:
            left += n
            ans.append(abs(right - left))
            right -= n
        return ans
