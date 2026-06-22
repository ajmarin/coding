class Solution:
    def queryString(self, s: str, n: int) -> bool:
        z = len(s)
        if n > z * (z + 1) >> 1:
            return False
        seen = set()
        for i in range(z):
            if s[i] == "0":
                continue
            num = 0
            for j in range(i, min(z, i + 31)):
                num = (num << 1) | (s[j] == "1")
                if num > n:
                    break
                seen.add(num)
        return len(seen) - (0 in seen) == n
