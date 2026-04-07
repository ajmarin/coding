class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        available, needed = Counter(s), Counter(target)
        return min(available[c] // needed[c] for c in needed)
