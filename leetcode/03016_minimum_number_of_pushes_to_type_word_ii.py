class Solution:
    def minimumPushes(self, word: str) -> int:
        ORDA = ord("a")
        freq = [word.count(chr(ORDA + i)) for i in range(26)]
        freq.sort(reverse=True)
        return sum(f * (1 + i // 8) for i, f in enumerate(freq))
