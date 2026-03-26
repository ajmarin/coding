MAX_POW = 3**20


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and MAX_POW % n == 0
