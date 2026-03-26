class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        divsum = num != 1
        for n in range(2, num):
            square = n * n
            if square > num:
                break
            if square == num:
                divsum += n
                break
            if num % n == 0:
                divsum = divsum + n + num // n
        return divsum == num
