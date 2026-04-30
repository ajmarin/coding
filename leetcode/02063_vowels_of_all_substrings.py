class Solution:
    def countVowels(self, word: str) -> int:
        VOWELS = set("aeiou")
        ans, n = 0, len(word)
        for left, c in enumerate(word):
            if c in VOWELS:
                ans += (left + 1) * (n - left)
        return ans
