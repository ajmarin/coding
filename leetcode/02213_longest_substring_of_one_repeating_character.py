class Solution:
    def longestRepeating(
        self, s: str, queryCharacters: str, queryIndices: List[int]
    ) -> List[int]:
        s, n = list(s), len(s)
        tree = [(1, 1, 1)] * (4 * n)

        def merge(u: int, l: int, r: int) -> None:
            ll, maxl, lr = tree[u << 1]
            rl, maxr, rr = tree[u << 1 | 1]
            m = (l + r) >> 1
            merged = max(maxl, maxr)
            if s[m] == s[m + 1]:
                merged = merged if merged > lr + rl else lr + rl
                if s[l] == s[m] and ll == m - l + 1:
                    ll += rl
                if s[m + 1] == s[r] and rr == r - m:
                    rr += lr
            return ll, merged, rr

        def build(u: int, l: int, r: int):
            if l == r:
                return
            m = (l + r) >> 1
            build(u << 1, l, m)
            build(u << 1 | 1, m + 1, r)
            tree[u] = merge(u, l, r)

        def update(u: int, pos: int, l=0, r=n - 1):
            if l == r:
                return
            m = (l + r) >> 1
            if pos <= m:
                update(u << 1, pos, l, m)
            else:
                update(u << 1 | 1, pos, m + 1, r)
            tree[u] = merge(u, l, r)

        build(1, 0, n - 1)
        ans = []
        for c, i in zip(queryCharacters, queryIndices):
            s[i] = c
            update(1, i)
            ans.append(tree[1][1])
        return ans
