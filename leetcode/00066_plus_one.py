class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        pos = len(digits) - 1
        carry = 1
        while pos > -1 and carry:
            carry = carry + digits[pos]
            digits[pos] = carry % 10
            carry //= 10
            pos -= 1
        if carry:
            digits.insert(0, carry)
        return digits