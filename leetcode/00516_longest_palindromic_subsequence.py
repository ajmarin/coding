class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @cache
        def dp(left, right):
            if left >= right:
                return 0
            indices = defaultdict(list)
            for i in range(left, right):
                indices[s[i]].append(i)
            return max(
                1 + (len(idx) > 1) + dp(idx[0] + 1, idx[-1]) for idx in indices.values()
            )

        return dp(0, len(s))
