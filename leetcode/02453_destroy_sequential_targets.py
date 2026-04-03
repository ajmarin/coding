class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        c = Counter([n % space for n in nums])
        highest = max(c.values())
        ans = 10**10
        for n in nums:
            if c[n % space] == highest:
                ans = ans if ans < n else n
        return ans
