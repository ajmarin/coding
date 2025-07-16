class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        ans = True
        while n and ans:
            ans &= n % 3 != 2
            n //= 3
        return ans

