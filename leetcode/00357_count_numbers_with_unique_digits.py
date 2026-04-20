F = [1]
for i in range(1, 10):
    F.append(i * F[-1])


class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if not n:
            return 1
        unique = 9 * F[9] // F[10 - n]
        return unique + self.countNumbersWithUniqueDigits(n - 1)
