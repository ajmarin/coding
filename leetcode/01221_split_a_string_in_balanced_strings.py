class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balanced, count = 0, 0
        for c in s:
            if c == 'R':
                count += 1
            else:
                count -= 1
            if count == 0:
                balanced += 1
        return balanced