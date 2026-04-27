class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = list(range(len(edges) + 1))

        def find(a):
            if parent[a] == a:
                return a
            pa = find(parent[a])
            parent[a] = pa
            return pa

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa == pb:
                return False
            parent[pa] = pb
            return True

        return next(e for e in edges if not union(*e))
