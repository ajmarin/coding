class Solution:
    def minSwaps(self, s: str) -> int:
        bal = lowest = 0
        for c in s:
            if c == "[":
                bal += 1
            else:
                bal -= 1
                lowest = lowest if lowest < bal else bal
        return (-lowest + 1) >> 1
