class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [0] * (rowIndex + 1)
        ans[0] = 1
        for i in range(1, rowIndex + 1):
            for j in range(i, 0, -1):
                ans[j] += ans[j - 1]
        return ans
