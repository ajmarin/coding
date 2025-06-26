class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans, num, left, zeroes = 0, 0, -1, 0
        for i, c in enumerate(s):
            num = (num << 1) | (c == '1')
            while num > k:
                left += 1
                if s[left] == '1':
                    num -= 1 << (i - left)
                else:
                    zeroes += 1
            ans = max(ans, zeroes + i - left)
        return ans

