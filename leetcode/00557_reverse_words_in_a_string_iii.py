class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(map(lambda part: part[::-1], s.split(' ')))