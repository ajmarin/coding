class Solution:
    def minWindow(self, s: str, t: str) -> str:
        min_length = len(s)
        ans = ""

        counts = Counter(t)
        missing = len(t)
        left = 0
        for right, c in enumerate(s):
            missing -= counts[c] > 0
            counts[c] -= 1
            if missing == 0:
                while counts[s[left]] < 0:
                    counts[s[left]] += 1
                    left += 1
                if right - left < min_length:
                    min_length = right - left
                    ans = s[left : right + 1]
                missing += 1
                counts[s[left]] += 1
                left += 1
        return ans
