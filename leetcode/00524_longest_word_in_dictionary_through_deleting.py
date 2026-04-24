class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        dictionary.sort(key=lambda w: (-len(w), w))
        for w in dictionary:
            it = iter(s)
            if all(c in it for c in w):
                return w
        return ""
