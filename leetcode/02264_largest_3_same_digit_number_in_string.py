class Solution:
    def largestGoodInteger(self, num: str) -> str:
        ans = ""
        prev = -1
        for c in num:
            if c == prev:
                count += 1
                if count == 3:
                    ans = max(ans, c * 3)
            else:
                count = 1
            prev = c
        return ans
