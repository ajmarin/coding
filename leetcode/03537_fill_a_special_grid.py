class Solution:
    def specialGrid(self, n: int) -> List[List[int]]:
        side = 1 << n
        ans = [[0] * side for _ in range(side)]

        self.val = 0

        def fill(r: int, c: int, jump: int):
            if jump == 0:
                ans[r][c] = self.val
                self.val += 1
                return
            nj = jump >> 1
            fill(r, c, nj)
            fill(r + jump, c, nj)
            fill(r + jump, c - jump, nj)
            fill(r, c - jump, nj)

        fill(0, side - 1, side >> 1)
        return ans
