class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        n = len(words)
        return all(count % n == 0 for count in Counter("".join(words)).values())
