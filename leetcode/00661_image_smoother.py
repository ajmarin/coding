class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        rows, cols = len(img), len(img[0])
        expanded = [
            [-1] * (cols + 2),
            *[[-1, *row, -1] for row in img],
            [-1] * (cols + 2),
        ]

        def avg(i, j):
            count = total = 0
            for di, dj in product((-1, 0, 1), (-1, 0, 1)):
                val = expanded[i + di][j + dj]
                if val != -1:
                    total += val
                    count += 1
            return total // count

        ans = []
        for i in range(1, rows + 1):
            ans_row = []
            for j in range(1, cols + 1):
                ans_row.append(avg(i, j))
            ans.append(ans_row)
        return ans
