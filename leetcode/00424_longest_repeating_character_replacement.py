class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = Counter()
        ans = left = max_rep = 0
        for right, c in enumerate(s):
            cnt[c] += 1
            max_rep = max_rep if max_rep > cnt[c] else cnt[c]
            if ans - max_rep >= k:
                cnt[s[left]] -= 1
                left += 1
            else:
                ans += 1
        return ans
