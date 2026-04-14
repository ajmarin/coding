BASE_16 = string.digits + string.ascii_uppercase[:6]
BASE_36 = string.digits + string.ascii_uppercase


class Solution:
    def concatHex36(self, n: int) -> str:
        b16 = b36 = ""

        nsq = n**2
        while nsq:
            b16 += BASE_16[nsq & 15]
            nsq >>= 4

        ncube = n**3
        while ncube:
            b36 += BASE_36[ncube % 36]
            ncube //= 36

        return b16[::-1] + b36[::-1]
