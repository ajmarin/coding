class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        prod, sum = 1, 0
        while n:
            digit = n % 10
            n //= 10
            prod *= digit
            sum += digit
        return prod - sum
