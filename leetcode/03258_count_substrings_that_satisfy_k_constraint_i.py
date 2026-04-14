class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        ans = left = ones = 0
        for right, c in enumerate(s):
            ones += c == "1"
            while ones > k and right - left - ones >= k:
                ones -= s[left] == "1"
                left += 1
            ans += right - left + 1
        return ans
