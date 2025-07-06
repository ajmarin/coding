def make_union_find(n):
    parent = list(range(n))
    rank = [0] * n
    return parent, rank

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])  # Path compression
    return parent[x]

def union(parent, rank, x, y):
    px, py = find(parent, x), find(parent, y)
    if px == py:
        return False
    rx, ry = rank[px], rank[py]
    if rx < ry:
        parent[px] = py
    else:
        parent[py] = px
        rank[px] += (rx > ry)
    return True


class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        p, r = make_union_find(c + 1)
        for u, v in connections:
            union(p, r, u, v)

        is_offline = [False] * (c + 1)
        groups = defaultdict(list)
        active_index = defaultdict(int)

        for i in range(1, c + 1):
            rank = find(p, i)
            groups[rank].append(i)

        ans = []
        for op, index in queries:
            if op == 2:
                is_offline[index] = True
                continue
            if not is_offline[index]:
                ans.append(index)
                continue
            group = find(p, index)
            g = groups[group]
            index = active_index[group]
            while index < len(g) and is_offline[g[index]]:
                index += 1
            active_index[group] = index
            if index < len(g):
                ans.append(g[index])
            else:
                ans.append(-1)
        return ans

