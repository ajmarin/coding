class Solution:
    def isFascinating(self, n: int) -> bool:
        s = str(n) + str(2 * n) + str(3 * n)
        return len(s) == len(set(s)) == 9 and "0" not in s
