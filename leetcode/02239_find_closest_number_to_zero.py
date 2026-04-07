class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans = min_dist = 10_000_000
        for n in nums:
            dist = abs(n)
            if dist < min_dist:
                ans = n
                min_dist = dist
            elif dist == min_dist and n > ans:
                ans = n
        return ans
