class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def lcm(x: int, y: int) -> int:
            return x * y // math.gcd(x, y)
        ab, ac, bc = map(lambda x: lcm(*x), ((a, b), (a, c), (b, c)))
        abc = lcm(a, bc)
        def divcount(z: int) -> int:
            return z // a + z // b + z // c - z // ab - z // bc - z // ac + z // abc
        left, right = 0, 2 * 10**9 + 1
        while left < right:
            mid = (left + right) >> 1
            if divcount(mid) < n:
                left = mid + 1
            else:
                right = mid
        return left