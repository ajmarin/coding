class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        area = R * C
        answer, index = [None] * area, 1
        answer[0] = r0, c0
        dr_dc = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        direction, dr, dc, side = 0, 0, 1, 1
        while index != area:
            for i in range(side):
                r0, c0 = r0 + dr, c0 + dc
                if 0 <= r0 < R and 0 <= c0 < C:
                    answer[index] = r0, c0
                    index += 1
            direction = (direction + 1) & 3
            dr, dc = dr_dc[direction]
            if not direction & 1:
                side += 1
        return answer