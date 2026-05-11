class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        change = {str(i): str(n) for i, n in enumerate(change)}

        n = len(num)
        digits = list(num)
        start = next((i for i, d in enumerate(digits) if change[d] > d), -1)
        if start == -1:
            return num

        for i in range(start, n):
            if change[digits[i]] < digits[i]:
                break
            digits[i] = change[digits[i]]
        return "".join(digits)
