MOD = 10**9 + 7


class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for l, r, k, v in queries:
            for i in range(l, r + 1, k):
                nums[i] = nums[i] * v % MOD
        xor = 0
        for n in nums:
            xor ^= n
        return xor
