@cache
def hash(word: str) -> str:
    delta = ord(word[0])
    return tuple((ord(c) - delta) % 26 for c in word)


class Solution:
    def countPairs(self, words: List[str]) -> int:
        return sum(v * (v - 1) for v in Counter(map(hash, words)).values()) >> 1
