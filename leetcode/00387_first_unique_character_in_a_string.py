class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt = Counter(s)
        return s.find(next((c for c in cnt if cnt[c] == 1), '$'))