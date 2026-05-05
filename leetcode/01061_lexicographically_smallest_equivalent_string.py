class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        mapping = {c: c for c in ascii_lowercase}

        def find(a):
            if a != mapping[a]:
                mapping[a] = find(mapping[a])
            return mapping[a]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa < pb:
                mapping[pb] = pa
            else:
                mapping[pa] = pb

        for a, b in zip(s1, s2):
            union(a, b)

        return "".join(mapping[find(c)] for c in baseStr)
