class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        L1, L2 = len(num1), len(num2)
        LEN = max(L1, L2)
        num1 = '0' * (LEN - L1) + num1
        num2 = '0' * (LEN - L2) + num2
        carry = 0
        ord0 = ord('0')
        ord0times2 = ord0 << 1
        ans = [None] * len(num1)
        for i in range(LEN - 1, -1, -1):
            carry = carry + ord(num2[i]) + ord(num1[i]) - ord0times2
            ans[i] = chr(carry % 10 + ord0)
            carry //= 10
        return (chr(carry + ord0) if carry else '') + ''.join(ans)