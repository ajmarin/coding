class Solution:
    PREFIX_TO_VALUE = [
        ("M", 1000),
        ("CM", 900),
        ("D", 500),
        ("CD", 400),
        ("C", 100),
        ("XC", 90),
        ("L", 50),
        ("XL", 40),
        ("X", 10),
        ("IX", 9),
        ("V", 5),
        ("IV", 4),
        ("I", 1),
    ]
    def romanToInt(self, s: str) -> int:
        r = 0
        for prefix, value in self.PREFIX_TO_VALUE:
            while s.startswith(prefix):
                r += value
                s = s[len(prefix):]
        return r