class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            r2, c2 = r2 + 1, c2 + 1
            ans[r1][c1] += 1
            if r2 < n:
                ans[r2][c1] -= 1
            if c2 < n:
                ans[r1][c2] -= 1
            if r2 < n and c2 < n:
                ans[r2][c2] += 1
        prev = ans[0]
        for r in range(1, n):
            row = ans[r]
            for c in range(n):
                row[c] += prev[c]
            prev = row
        return list(map(list, map(accumulate, ans)))
