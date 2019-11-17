class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        s = sum(nums)
        mod3 = collections.defaultdict(list)
        for n in nums:
            mod3[n % 3].append(n)
        rem, sub = s % 3, 0
        if rem:
            sub = min(mod3[rem])
            if len(mod3[3 - rem]) > 1:
                mod3[3 - rem].sort()
                sub = min(sub, sum(mod3[3 - rem][:2]))
        return s - sub