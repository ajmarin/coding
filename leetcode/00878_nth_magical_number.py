import bisect, math

class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        lcm = (a * b) // math.gcd(a, b)

        class MagicalCount:
            def __getitem__(self, z):
                return z // a + z // b - z // lcm

        return bisect.bisect_left(MagicalCount(), n, 0, 10**14) % (10 ** 9 + 7)

