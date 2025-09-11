VOWELS = set('aeiouAEIOU')
class Solution:
    def sortVowels(self, s: str) -> str:
        viter = iter(sorted(v for v in s if v in VOWELS))
        return ''.join(next(viter) if c in VOWELS else c for c in s)

