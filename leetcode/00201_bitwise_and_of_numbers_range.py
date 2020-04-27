class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        answer = m & n
        isize = n - m + 1
        unset = 1
        while unset < isize:
            answer &= ~unset
            unset <<= 1
        return answer