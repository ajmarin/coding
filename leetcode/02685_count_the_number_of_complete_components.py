def prep_union_find(n):
    return list(range(n)), [0] * n

def find(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(parent, rank, x1, x2):
    p1, p2 = find(parent, x1), find(parent, x2)
    if p1 == p2: return False

    if rank[p1] > rank[p2]:
        parent[p2] = p1
        rank[p1] += rank[p2]
    else:
        parent[p1] = p2
        rank[p2] += rank[p1]
    return True

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        p, r = prep_union_find(n)
        for u, v in edges:
            union(p, r, u, v)
        n_counts = Counter(map(lambda i: find(p, i), range(n)))
        e_counts = Counter(map(lambda e: p[e[0]], edges))
        return sum(1 for k, cnt in n_counts.items() if e_counts[k] == (cnt * (cnt - 1)) >> 1)

