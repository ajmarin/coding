VOWELS = set("aeiou")


class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        return sum(w[0] in VOWELS and w[-1] in VOWELS for w in words[left : right + 1])
