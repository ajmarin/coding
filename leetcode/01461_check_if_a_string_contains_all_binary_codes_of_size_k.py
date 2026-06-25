class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = 1 << k
        mask = n - 1
        if len(s) - k < mask:
            return False
        seen = [False] * n
        num = int(s[: k - 1] or "0", 2)
        for i in range(k - 1, len(s)):
            num = ((num << 1) & mask) ^ (s[i] == "1")
            seen[num] = True
        return all(seen)
