class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        ORDA = ord("a")
        ans = 0
        freq = [0] * 3
        left = iter(s)
        for right, c in enumerate(s):
            freq[ord(c) - ORDA] += 1
            while all(freq):
                ans += n - right
                freq[ord(next(left)) - ORDA] -= 1
        return ans
