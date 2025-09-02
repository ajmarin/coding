class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        n = len(points)
        points.sort(key=lambda p: (p[0], -p[1]))
        yvals = [y for _, y in points]
        ans = 0
        for i in range(n):
            yi = yvals[i]
            for j in range(i + 1, n):
                yj = yvals[j]
                ans += yj <= yi and all(yk < yj or yk > yi for yk in yvals[i + 1:j])
        return ans

