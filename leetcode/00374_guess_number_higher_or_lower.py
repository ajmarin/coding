# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        low, high = 1, n
        while low <= high:
            mid = (low + high) >> 1
            r = guess(mid)
            if r == 0:
                return mid
            if r == -1:
                high = mid - 1
            else:
                low = mid + 1
        return low

