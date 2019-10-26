class Solution:
    LINES = list(map(set, ["qwertyuiop", "asdfghjkl", "zxcvbnm"]))
    def findWords(self, words: List[str]) -> List[str]:
        return [w for w in words if any(len(set(w.lower()) - line) == 0 for line in self.LINES)]