def prep_union_find(n):
    parent = [i for i in range(n)]
    rank = [1] * n
    return parent, rank

def find(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(parent, rank, x1, x2):
    p1, p2 = find(parent, x1), find(parent, x2)
    if p1 == p2:
        return False

    if rank[p1] > rank[p2]:
        parent[p2] = p1
        rank[p1] += rank[p2]
    else:
        parent[p1] = p2
        rank[p2] += rank[p1]
    return True

class Solution:
    def minTime(self, n: int, edges: List[List[int]], k: int) -> int:
        edges.sort(key=lambda e: -e[2])
        parent, rank = prep_union_find(n)
        for u, v, t in edges:
            if union(parent, rank, u, v):
                if (n := n - 1) < k:
                    return t
        return 0

