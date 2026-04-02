class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        return 1 + next(
            (i for i, s in enumerate(sentence.split(" ")) if s.startswith(searchWord)),
            -2,
        )
