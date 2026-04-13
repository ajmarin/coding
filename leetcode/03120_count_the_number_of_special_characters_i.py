class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        cnt = Counter(word)
        return sum(cnt[c] > 0 and cnt[c.upper()] > 0 for c in ascii_lowercase)
