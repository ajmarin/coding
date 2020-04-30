class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = count = 0
        for n in nums:
            if n == 0:
                ans = max(ans, count)
                count = 0
            else:
                count += 1
        return max(ans, count)