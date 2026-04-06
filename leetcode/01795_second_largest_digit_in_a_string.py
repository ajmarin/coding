class Solution:
    def secondHighest(self, s: str) -> int:
        highest = second = chr(ord("0") - 1)
        for c in s:
            if not c.isdigit():
                continue
            if c > highest:
                highest, second = c, highest
            elif c < highest and c > second:
                second = c
        return int(second) if second.isdigit() else -1
