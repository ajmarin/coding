SQUARES = [n * n for n in range(1, 251)]
SQUARE_SET = set(SQUARES)


class Solution:
    def countTriples(self, n: int) -> int:
        n *= n
        ans = 0

        for i, a in enumerate(SQUARES):
            for b in SQUARES[i + 1 :]:
                res = a + b
                if res in SQUARE_SET and res <= n:
                    ans += 2

        return ans
