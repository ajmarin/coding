@cache
def dp(i: int) -> bool:
    return False if i == 0 else any(not dp(i - j**2) for j in range(1, isqrt(i) + 1))


pre = [dp(i) for i in range(100001)]


class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        return pre[n]
