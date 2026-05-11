class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        dsum, idx, nums = ([0] for _ in range(3))

        p10 = [1]
        for i in range(len(s)):
            p10.append(p10[-1] * 10 % MOD)

        last = 0
        for d in map(int, s):
            if d:
                nums.append((nums[-1] * 10 + d) % MOD)
                dsum.append(dsum[-1] + d)
                last += 1
            idx.append(last)

        ans = []
        for q in queries:
            l = idx[q[0]]
            r = idx[q[1] + 1]
            ans.append((nums[r] - nums[l] * p10[r - l]) * (dsum[r] - dsum[l]) % MOD)
        return ans
