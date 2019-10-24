class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        guess = num
        while guess * guess > num:
            guess = (guess + num // guess) >> 1
        return guess * guess == num