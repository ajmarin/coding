class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        ans = n * (n + 1) >> 1
        cnt = Counter()
        left = -1
        for right, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] >= k:
                cnt[s[left := left + 1]] -= 1
            ans -= right - left
        return ans
