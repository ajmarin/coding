class Solution:
    def minimumChairs(self, s: str) -> int:
        ans = chairs = 0
        for c in s:
            if c == "E":
                chairs += 1
                ans = max(ans, chairs)
            else:
                chairs -= 1
        return ans
