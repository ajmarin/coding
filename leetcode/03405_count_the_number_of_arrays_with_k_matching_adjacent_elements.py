N = 10**5 + 1
MOD = 10**9 + 7
f = [1] + [0] * N
invf = [1] + [0] * N

for i in range(1, N):
    f[i] = f[i - 1] * i % MOD
    invf[i] = pow(f[i], MOD - 2, MOD)

# computes C(n, k) % p
# n! / (k! (n-k)!) % p
def comb(n: int, k: int) -> int:
    return f[n] * invf[k] * invf[n - k] % MOD

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        # m * (m - 1) ** (n - k - 1) * C(n - 1, k)
        return m * pow(m - 1, n - k - 1, MOD) * comb(n - 1, k) % MOD

