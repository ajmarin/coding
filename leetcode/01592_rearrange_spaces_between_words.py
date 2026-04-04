class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = [w for w in text.split(" ") if w]
        spaces = len(text) - sum(len(w) for w in words)
        if len(words) == 1:
            return words[0] + " " * spaces
        gaps = len(words) - 1
        return (" " * (spaces // gaps)).join(words) + " " * (spaces % gaps)
