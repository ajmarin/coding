class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        '''
        Given a palindrome number of the form:
        10**n * (10**n - a) + rev(10**n - a)
        Let's say b = 10**n - a, then we have:
        10**n * (10**n - a) + b
        We want to get this number from the product of two numbers that have n-digits
        10**n * (10**n - a) + b = (10**n - p)*(10**n - q)
        Simplifying this:
        10**n * (p + q - a) = p * q - b
        Since we know a is non-zero and b is non-zero, we can try to achieve:
        p + q = a
        p * q = b
        Solving this
        p + (b / p) = a
        p**2 + b = ap
        p**2 - ap + b = 0
        p = (a +- sqrt(a**2 - 4b)) / 2
        '''
        upper = 10**n
        for a in range(1, upper):
            x = upper - a
            b = int(str(x)[::-1])
            z = a * a - (b << 2)
            if z < 0:
                continue
            t = int(z**.5)
            if t * t == z and not (a + t) & 1:
                p = (a - t) >> 1
                q = b // p
                print(f"{10**n * x + b} = {10**n - p} * {10**n - q}")
                return (10**n * x + b) % 1337
        return -1