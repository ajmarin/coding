class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        VOWELS = set("aeiou")
        for right in range(len(s) - 1, -1, -1):
            if s[right] not in VOWELS:
                break
        else:
            return ""
        return s[: right + 1]
