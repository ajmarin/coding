class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        c, n = Counter(chain(*grid)), len(grid)
        ans = [0, 0]
        for i in range(1, n * n + 1):
            if c[i] == 0:
                ans[1] = i
            elif c[i] == 2:
                ans[0] = i
        return ans
