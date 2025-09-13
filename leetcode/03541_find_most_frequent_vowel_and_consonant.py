class Solution:
    def maxFreqSum(self, s: str) -> int:
        cnt = Counter(s)
        return max(cnt[c] for c in 'aeiou') + max(cnt[c] for c in 'bcdfghjklmnpqrstvwxyz')

