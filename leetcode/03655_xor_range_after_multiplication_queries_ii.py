MOD = 10**9 + 7


class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        by_k = defaultdict(list)
        root_n = isqrt(n)

        for q in queries:
            k = q[2]
            if k < root_n:
                by_k[k].append(q)
            else:
                l, r, _, v = q
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % MOD

        mult = [1] * (n + root_n)
        for k, query_infos in by_k.items():
            mult[:] = [1] * (n + root_n)
            for l, r, _, v in query_infos:
                mult[l] = mult[l] * v % MOD
                last = l + ((r - l) // k + 1) * k
                mult[last] = mult[last] * pow(v, -1, MOD) % MOD
            for i in range(k, n):
                mult[i] = (mult[i] * mult[i - k]) % MOD
            for i in range(n):
                nums[i] = (nums[i] * mult[i]) % MOD

        ans = 0
        for n in nums:
            ans ^= n
        return ans
