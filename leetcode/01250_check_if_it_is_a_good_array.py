class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)
        n = nums[0]
        for i in range(1, len(nums)):
            n = gcd(n, nums[i])
        return n == 1