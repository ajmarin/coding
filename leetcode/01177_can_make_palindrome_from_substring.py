class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        ORDA = ord("a")
        pfx = [0]
        for c in s:
            pfx.append(pfx[-1] ^ (1 << (ord(c) - ORDA)))
        return [(pfx[r + 1] ^ pfx[l]).bit_count() >> 1 <= k for l, r, k in queries]
