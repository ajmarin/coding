class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        prev = "2"
        longest = [0, 0, 0]
        count = 0
        for c in f"{s}_":
            if c != prev:
                index = int(prev)
                longest[index] = max(longest[index], count)
                count = 1
            else:
                count += 1
            prev = c
        return longest[1] > longest[0]
