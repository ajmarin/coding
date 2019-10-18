class Solution:
    def addBinary(self, a: str, b: str) -> str:
        maxlen = max(len(a), len(b))
        a = a[::-1] + ("0" * (maxlen - len(a)))
        b = b[::-1] + ("0" * (maxlen - len(b)))
        result = []
        carry = 0
        for i in range(maxlen):
            carry = carry + (ord(a[i]) - ord("0")) + (ord(b[i]) - ord("0"))
            result.append(carry & 1)
            carry >>= 1
        if carry:
            result.append("1")
        return ''.join(map(str, result[::-1]))