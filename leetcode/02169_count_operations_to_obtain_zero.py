class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        op = 0
        while num1 and num2:
            if num1 < num2:
                num1, num2 = num2, num1
            op += num1 // num2
            num1 %= num2
        return op
