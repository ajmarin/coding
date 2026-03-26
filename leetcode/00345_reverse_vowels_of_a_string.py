VOWELS = set("aeiouAEIOU")


class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = [c for c in s if c in VOWELS]
        return "".join([vowels.pop() if c in VOWELS else c for c in s])
