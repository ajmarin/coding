class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set("aeiouAEIOU")
        n = len(s)
        return sum(c in vowels for c in s[: n // 2]) == sum(
            c in vowels for c in s[n // 2 :]
        )
