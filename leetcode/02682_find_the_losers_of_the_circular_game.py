class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        ball = 0
        losers = set(range(1, n))
        for i in range(1, n + 1):
            ball = (ball + i * k) % n
            if ball not in losers:
                break
            losers.remove(ball)
        return [i + 1 for i in losers]
