class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        l1, l2 = len(s1), len(s2)
        s1, s2 = [ord(c) for c in s1], [ord(c) for c in s2]

        @cache
        def dp(i=0, j=0):
            if i == l1 or j == l2:
                return sum(s1[i:]) + sum(s2[j:])
            if s1[i] == s2[j]:
                return dp(i + 1, j + 1)
            return min(s1[i] + dp(i + 1, j), s2[j] + dp(i, j + 1))

        return dp()
