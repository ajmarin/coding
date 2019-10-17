class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        start = 0
        last_seen = dict()
        for i in range(len(s)):
            ls = last_seen.get(s[i])
            if ls is not None and ls + 1 > start:
                start = ls + 1
            last_seen[s[i]] = i
            longest = max(longest, i - start + 1)    
        return longest