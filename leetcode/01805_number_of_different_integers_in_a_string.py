class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        num, num_set = "", set()
        for c in word:
            if c.isdigit():
                num += c
            elif num:
                num_set.add(int(num))
                num = ""
        if num:
            num_set.add(int(num))
        return len(num_set)
