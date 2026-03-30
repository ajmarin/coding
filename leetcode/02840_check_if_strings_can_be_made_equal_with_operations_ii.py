class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        even = Counter(s1[::2]) - Counter(s2[::2])
        if not all(v == 0 for v in even.values()):
            return False
        odd = Counter(s1[1::2]) - Counter(s2[1::2])
        return all(v == 0 for v in odd.values())
