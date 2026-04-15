class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        VOWELS = set("aeiou")
        v = sum(c in VOWELS for c in s)
        c = sum(c not in VOWELS and c != " " and not c.isdigit() for c in s)
        return v // c if c else 0
