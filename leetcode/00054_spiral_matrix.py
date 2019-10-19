class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        answer = []
        rows = len(matrix)
        if rows == 0:
            return answer
        cols = len(matrix[0])
        pos = [0, 0]
        limits = [0, rows, 0, cols]
        dx_dy = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        limits_change = [
            [1, 0, 0, 0],
            [0, 0, 0, -1],
            [0, -1, 0, 0],
            [0, 0, 1, 0],
        ]
        d = 0
        while len(answer) < rows * cols:
            pp = 1 - (d & 1)
            lmin = limits[pp << 1]
            lmax = limits[1 + (pp << 1)]
            while lmin <= pos[pp] and pos[pp] < lmax:
                answer.append(matrix[pos[0]][pos[1]])
                pos[pp] += dx_dy[d][pp]
            pos[pp] -= dx_dy[d][pp]
            for i in range(len(limits)):
                limits[i] += limits_change[d][i]
            pos[0] = min(max(pos[0], limits[0]), limits[1] - 1)
            pos[1] = min(max(pos[1], limits[2]), limits[3] - 1)
            d = (d + 1) % 4
        return answer