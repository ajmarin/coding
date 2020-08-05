class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        while num:
            if num == 1:
                return True
            if num & 3:
                break
            num >>= 2
        return False