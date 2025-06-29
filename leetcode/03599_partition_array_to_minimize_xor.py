class Solution:
    def minXor(self, nums: List[int], K: int):
        N = len(nums)
        prefix_xor = list(accumulate(nums, operator.xor, initial=0))

        @cache
        def dp(i, k):
            if k == 1:
                return prefix_xor[i]
            ans = inf
            for j in range(k - 1, i):
                prev = dp(j, k - 1)
                new = prefix_xor[i] ^ prefix_xor[j]
                if prev >= new and prev < ans:
                    ans = prev
                elif new > prev and new < ans:
                    ans = new
            return ans

        return dp(N, K)

