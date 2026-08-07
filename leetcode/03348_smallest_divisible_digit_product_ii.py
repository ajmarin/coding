class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        tmp = t
        for p in (2, 3, 5, 7):
            while tmp % p == 0:
                tmp //= p
        if tmp != 1:
            return "-1"

        n = len(num)
        rem = [t]
        first_zero = n
        inum = [*map(int, num)]
        for i in range(n):
            if not inum[i]:
                first_zero = i
                break
            rem.append(rem[-1] // gcd(rem[-1], inum[i]))

        if rem[-1] == 1 and first_zero == n:
            return num

        for i in range(min(first_zero, n - 1), -1, -1):
            while True:
                inum[i] += 1
                if inum[i] > 9:
                    break
                curr_t = rem[i] // gcd(rem[i], inum[i])
                d = 9
                for j in range(n - 1, i, -1):
                    while curr_t % d:
                        d -= 1
                    curr_t //= d
                    inum[j] = d
                if curr_t == 1:
                    return "".join(map(str, inum))

        digits = []
        for d in range(9, 1, -1):
            while t % d == 0:
                digits.append(str(d))
                t //= d
        ans = "".join(reversed(digits))
        return "1" * (len(num) + 1 - len(ans)) + ans
