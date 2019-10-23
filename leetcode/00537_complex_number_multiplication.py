class Solution:
    def parse(self, s: str) -> (int, int):
        return map(int, s[:-1].split('+'))
    def complexNumberMultiply(self, a: str, b: str) -> str:
        a1, b1 = self.parse(a)
        a2, b2 = self.parse(b)
        return f"{a1*a2-b1*b2}+{a2*b1+b2*a1}i"