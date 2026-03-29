class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return all(
            s1[i] == s2[i] or (s1[i] == s2[(i + 2) % 4] and s1[(i + 2) % 4] == s2[i])
            for i in range(4)
        )
