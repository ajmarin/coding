class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        c1 = Counter(words1)
        return sum(c1[w] == count == 1 for w, count in Counter(words2).items())
