class Solution:
    def bowlSubarrays(self, nums: List[int]) -> int:
        ans = 0
        s = []
        for n in nums:
            while s and s[-1] < n:
                s.pop()
                ans += 1 if s else 0
            s.append(n)
        return ans
