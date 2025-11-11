number_re = re.compile(r"[-+]?(\d+\.?\d*|\d*\.\d+)([eE][-+]?\d+)?")


class Solution:
    def isNumber(self, s: str) -> bool:
        return number_re.fullmatch(s) is not None
