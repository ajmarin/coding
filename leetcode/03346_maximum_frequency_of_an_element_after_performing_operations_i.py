class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        n = max(nums) + 2
        cnt, diff = [0] * n, [0] * n
        cap = n - k - 1
        for x in nums:
            cnt[x] += 1
            diff[0 if x < k else x - k] += 1
            diff[-1 if x >= cap else x + k + 1] -= 1

        ans = freq = 0
        for i in range(n):
            freq += diff[i]
            cand = numOperations + cnt[i] if freq - cnt[i] > numOperations else freq
            ans = ans if ans >= cand else cand
        return ans
