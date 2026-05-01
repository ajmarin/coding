class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        row_mines = [[-1] for _ in range(n)]
        col_mines = [[-1] for _ in range(n)]
        for row, col in mines:
            insort(row_mines[row], col)
            insort(col_mines[col], row)
        for arr in chain(row_mines, col_mines):
            arr.append(n)
        col_pos = [1] * n
        ans = 0
        for r in range(n):
            mines = row_mines[r]
            right, left, pos = mines[1], -1, 1
            for c in range(n):
                if c == right:
                    left, right = right, mines[pos := pos + 1]
                    col_pos[c] += 1
                    continue
                row_span = min(c - left, right - c)
                cpos = col_pos[c]
                up, down = col_mines[c][cpos - 1], col_mines[c][cpos]
                col_span = min(r - up, down - r)
                ans = max(ans, min(row_span, col_span))
        return ans
