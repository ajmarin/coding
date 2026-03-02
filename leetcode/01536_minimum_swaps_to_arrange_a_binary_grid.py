class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        N = len(grid)
        last_one = [-1] * N
        for i, row in enumerate(grid):
            last_one[i] = next((j for j in range(N - 1, -1, -1) if row[j] == 1), -1)
        steps = 0
        for i in range(N):
            for j in range(i, N):
                if last_one[j] <= i:
                    break
            else:
                return -1
            steps += j - i
            tmp = last_one[j]
            for k in range(j, i, -1):
                last_one[k] = last_one[k - 1]
            last_one[i] = tmp
        return steps
