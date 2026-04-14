class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        left, right = p.split("*")
        lidx, ridx = s.find(left), s.rfind(right)
        return lidx + len(left) <= ridx if lidx != -1 and ridx != -1 else False
