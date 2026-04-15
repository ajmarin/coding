class Solution:
    def scoreBalance(self, s: str) -> bool:
        ints = [ord(c) - ord("a") + 1 for c in s]
        total = sum(ints)
        curr = 0
        for n in ints:
            curr += n << 1
            if curr == total:
                return True
        return False
