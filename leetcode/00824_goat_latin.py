class Solution:
    def toGoatLatin(self, S: str) -> str:
        transform = lambda s, a: (s if s[0].lower() in 'aeiou' else s[1:] + s[0]) + 'ma' + 'a' * a
        return ' '.join(transform(word, i) for i, word in enumerate(S.split(), 1))