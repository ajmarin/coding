class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        c = Counter()
        left = max_score = 0
        for right, char in enumerate(s):
            c[char] += 1
            if c[char] == 3:
                max_score = right - left if right - left > max_score else max_score
                while c[char] > 2:
                    c[s[left]] -= 1
                    left += 1
        return max(max_score, len(s) - left)
