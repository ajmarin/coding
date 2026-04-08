class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split(" ")
        return all(words[i - 1][-1] == word[0] for i, word in enumerate(words))
