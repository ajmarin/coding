class Solution:
    def arrangeWords(self, text: str) -> str:
        pieces = text.lower().split(' ')
        pieces.sort(key=lambda s: len(s))
        pieces[0] = pieces[0][0].upper() + pieces[0][1:]
        return ' '.join(pieces)