class Solution:
    def minChanges(self, n: int, k: int) -> int:
        ans = 0
        for i in range(32):
            bit = 1 << i
            if k & bit and not n & bit:
                return -1
            ans += n & bit and not k & bit
        return ans
