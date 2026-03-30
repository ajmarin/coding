class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        c = Counter(deck)
        n = len(deck)
        if len(c) == 1 and n > 1:
            return True
        for x in range(2, n):
            if x * x > n:
                break
            div = n // x
            if all(count % x == 0 for count in c.values()) or all(
                count % div == 0 for count in c.values()
            ):
                return True
        return False
