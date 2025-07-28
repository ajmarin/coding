VOWELS = set('aeiou')

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans = vowels = 0
        left = iter(s)
        for i, c in enumerate(s):
            if i >= k: vowels -= next(left) in VOWELS
            vowels += c in VOWELS
            ans = vowels if vowels > ans else ans
        return ans

