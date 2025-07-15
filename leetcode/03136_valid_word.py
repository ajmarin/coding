VOWELS = set('aeiouAEIOU')

class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3: return False
        consonant = vowel = False
        for c in word:
            if c in string.ascii_letters:
                is_vowel = c in VOWELS
                vowel |= is_vowel
                consonant |= not is_vowel
            elif c in string.digits: pass
            else: return False
        return vowel and consonant

