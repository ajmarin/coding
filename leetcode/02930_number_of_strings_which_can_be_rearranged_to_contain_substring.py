MOD = 10**9 + 7


@cache
def dp(i, l, e, t):
    if i == 0:
        return l and t and e > 1
    i -= 1
    return (
        dp(i, 1, e, t)
        + dp(i, l, min(2, e + 1), t)
        + dp(i, l, e, 1)
        + 23 * dp(i, l, e, t)
    ) % MOD


class Solution:
    def stringCount(self, n: int) -> int:
        return dp(n, 0, 0, 0)
