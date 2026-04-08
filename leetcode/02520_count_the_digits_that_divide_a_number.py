class Solution:
    def countDigits(self, num: int) -> int:
        ans = 0
        temp = num
        while temp:
            ans += num % (temp % 10) == 0
            temp //= 10
        return ans
