MOD = 10**9 + 7


class Fancy:
    def __init__(self):
        self.seq = []
        self.inc = 0
        self.mul = 1

    def append(self, val: int) -> None:
        adjusted = (val - self.inc) * pow(self.mul, MOD - 2, MOD)
        self.seq.append(adjusted % MOD)

    def addAll(self, inc: int) -> None:
        self.inc = (self.inc + inc) % MOD

    def multAll(self, m: int) -> None:
        self.inc = (self.inc * m) % MOD
        self.mul = (self.mul * m) % MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.seq):
            return -1
        return (self.seq[idx] * self.mul + self.inc) % MOD
