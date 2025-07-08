class Solution:
    def addMinimum(self, word: str) -> int:
        wanted = cycle("abc")
        changes = 0
        for c in word:
            while next(wanted) != c:
                changes += 1
        return changes + 2 - "abc".index(word[-1])

