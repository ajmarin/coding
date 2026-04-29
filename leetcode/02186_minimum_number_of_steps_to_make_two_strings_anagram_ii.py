class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cs, ct = Counter(s), Counter(t)
        return sum(abs(cs[c] - ct[c]) for c in ascii_lowercase)
