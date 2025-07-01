class Solution:
    def possibleStringCount(self, w: str) -> int:
        return 1 + sum(w[i] == c for i, c in enumerate(w[1:]))

