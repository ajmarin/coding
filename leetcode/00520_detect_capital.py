class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        caps = lambda c: 'A' <= c <= 'Z'
        cnt = len(list(filter(caps, word)))
        return cnt == 0 or cnt == len(word) or cnt == 1 and caps(word[0])