class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ri, rj = next(
            (i, j) for i, j in product(range(8), range(8)) if board[i][j] == "R"
        )
        ans = 0
        for di, dj in ((0, -1), (-1, 0), (0, 1), (1, 0)):
            for k in range(1, 8):
                ni, nj = ri + k * di, rj + k * dj
                if ni < 0 or ni >= 8 or nj < 0 or nj >= 8:
                    break
                if board[ni][nj] != ".":
                    ans += board[ni][nj] == "p"
                    break
        return ans
