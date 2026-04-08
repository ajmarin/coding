class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            digits = []
            while n:
                digits.append(n % 10)
                n //= 10
            while digits:
                ans.append(digits.pop())
        return ans
