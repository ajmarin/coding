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


def is_connected(parent, rank):
    root = find(parent, 0)
    return all(find(parent, i) == root for i in range(1, len(parent)))


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        ans = 10**6
        costs = []
        edge_count = 0

        parent, rank = make_union_find(n)

        to_pick = []
        for u, v, s, must in edges:
            if must:
                if not union(parent, rank, u, v):
                    return -1
                edge_count += 1
                ans = min(ans, s)
            else:
                to_pick.append((s, u, v))

        to_pick.sort(reverse=True)
        for s, u, v in to_pick:
            if not union(parent, rank, u, v):
                continue
            edge_count += 1
            costs.append(s)
            if edge_count == n - 1:
                break

        if edge_count != n - 1 or not is_connected(parent, rank):
            return -1
        for i in range(min(k, len(costs))):
            costs[~i] *= 2
        return min(*costs[-k - 1:], ans, 10**6)

