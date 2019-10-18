class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        result = [0] * 221
        num1 = [ord(c) - ord('0') for c in num1][::-1]
        num2 = [ord(c) - ord('0') for c in num2][::-1]
        l1, l2 = len(num1), len(num2)
        for i in range(l1):
            for j in range(l2):
                result[i + j] += num1[i] * num2[j]
        carry, index = 0, 0
        while index < (l1 + l2) or carry:
            carry = carry + result[index]
            result[index] = carry % 10
            carry //= 10
            index += 1
        return ''.join(map(str, result[:index][::-1])).lstrip('0') or '0'