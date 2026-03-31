class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num = [0] * 4 + num
        i = -1
        while k:
            rest = k % 10
            k //= 10
            total = num[i] + rest
            k += total > 9
            num[i] = total % 10
            i -= 1
        trim = next((i for i in range(len(num)) if num[i] != 0), -1)
        return num[trim:] if trim != -1 else num
