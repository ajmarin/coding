class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        ans = last_change = last_group_size = 0
        prev = "2"
        for i, c in enumerate(s + "2"):
            if c != prev:
                size = i - last_change
                ans += size if size < last_group_size else last_group_size
                last_change = i
                last_group_size = size
            prev = c
        return ans
