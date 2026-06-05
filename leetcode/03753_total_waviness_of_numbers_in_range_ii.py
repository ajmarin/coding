class Solution:
    waves = []
    for i in range(1000):
        r = i % 10
        m = (i // 10) % 10
        l = (i // 100) % 10
        if l < m > r or l > m < r:
            waves.append(i)

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.get_waviness(num2) - self.get_waviness(num1 - 1)

    def get_waviness(self, n: int) -> int:
        if n < 100:
            return 0
        s = str(n)
        pre, mid, suf = [], [], []
        for i in range(len(s) - 2):
            pre.append(int(s[:i] or 0))
            mid.append(int(s[i : i + 3]))
            suf.append(int(s[i + 3 :] or 0))
        return sum(self.solve(pre, mid, suf, w) for w in self.waves)

    def solve(self, pre: List[int], mid: List[int], suf: List[int], wave: int) -> int:
        ans = 0
        p = wave < 100
        for power, pre, mid, suf in zip(range(len(pre) - 1, -1, -1), pre, mid, suf):
            pre -= p
            ans += (pre + 1 if mid > wave else max(0, pre)) * 10**power
            if mid == wave:
                ans += (pre >= 0) * (suf + 1)
        return ans
