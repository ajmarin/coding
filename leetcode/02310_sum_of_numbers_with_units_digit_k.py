class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0: return 0
        t = num % 10
        for i in range(1, 11):
            mul = i * k
            if mul % 10 == t and mul <= num:
                return i
        return -1

