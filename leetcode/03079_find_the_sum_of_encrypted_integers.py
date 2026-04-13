class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        digits = [0] * 4
        for n in nums:
            maxd = 0
            for i in range(8):
                d = n % 10
                maxd = d if d > maxd else maxd
                n //= 10
                if not n:
                    break
            for i in range(i, -1, -1):
                digits[i] += maxd
        ans, power = 0, 1
        for d in digits:
            ans += power * d
            power *= 10
        return ans
