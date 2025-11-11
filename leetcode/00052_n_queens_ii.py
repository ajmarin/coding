class Solution:
    @cache
    def totalNQueens(self, n: int) -> List[List[str]]:
        def bt(row: int, cols=0, posd=0, negd=0):
            if row == n:
                return 1
            solutions = 0

            for col in range(n):
                pos = row - col + n
                neg = row + col
                if cols & (1 << col) or posd & (1 << pos) or negd & (1 << neg):
                    continue
                solutions += bt(
                    row + 1, cols | (1 << col), posd | (1 << pos), negd | (1 << neg)
                )
            return solutions

        return bt(0)
