class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any(c in s for c in 'aeiou')

