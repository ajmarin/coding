class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        N = len(piles)
        prefix = list(accumulate(piles, initial=0))

        @cache
        def dp(i: int, m: int) -> int:
            if i + 2 * m >= N:
                return prefix[N] - prefix[i]
            pfxi = prefix[i]
            return max(
                prefix[i + x] - pfxi - dp(i + x, max(x, m)) for x in range(1, 2 * m + 1)
            )

        return (dp(0, 1) + sum(piles)) // 2
