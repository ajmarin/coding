class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        ans = min(divisors)
        best = 0
        for d in sorted(divisors):
            score = len([n for n in nums if n % d == 0])
            if score > best:
                best = score
                ans = d
        return ans
