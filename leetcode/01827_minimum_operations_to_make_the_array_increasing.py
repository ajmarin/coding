class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans, prev = 0, nums[0]
        for n in nums[1:]:
            if n > prev:
                prev = n
            else:
                prev = prev + 1
                ans += prev - n
        return ans
