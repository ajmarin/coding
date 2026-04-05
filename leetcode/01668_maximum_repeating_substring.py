class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        k = 1
        rep = word
        while rep in sequence:
            rep += word
            k += 1
        return k - 1
