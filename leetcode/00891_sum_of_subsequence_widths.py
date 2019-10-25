class Solution:
    def sumSubseqWidths(self, A: List[int]) -> int:
        N = len(A)
        A.sort()
        MOD = 10**9 + 7
        mul = [0] * N
        for i in range(1, N):
            mul[i] = (1 + 2 * mul[i - 1]) % MOD
        ans, max_pos = 0, N - 1
        for i, x in enumerate(A):
            ans += (mul[i] - mul[max_pos]) * x
            ans %= MOD
            max_pos -= 1
        return ans