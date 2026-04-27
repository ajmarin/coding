class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        proportion = ceil(len(b) / len(a))
        a_ext = a * proportion
        if b in a_ext:
            return proportion
        return proportion + 1 if b in a + a_ext else -1
