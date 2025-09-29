class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @cache
        def dp(l, r):
            if r - l < 3:
                return 0
            if r - l == 3:
                return values[l] * values[l + 1] * values[l + 2]
            endsp = values[l] * values[r - 1]
            res = inf
            for i in range(l + 1, r - 1):
                cand = endsp * values[i] + dp(l, i + 1) + dp(i, r)
                res = cand if cand < res else res
            return res

        return dp(0, len(values))
