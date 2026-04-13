class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        return any((b + a) in s for a, b in pairwise(s))
