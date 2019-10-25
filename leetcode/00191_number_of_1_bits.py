class Solution(object):
    def hammingWeight(self, n):
        ans = 0
        while n:
            ans += n & 1
            n >>= 1
        return ans