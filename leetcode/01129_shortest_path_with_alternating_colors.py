class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        blue = collections.defaultdict(collections.deque)
        red = collections.defaultdict(collections.deque)
        for f, t in blue_edges: blue[f].append(t)
        for f, t in red_edges: red[f].append(t)
        edges = [blue, red]
        q = collections.deque([(0, 0, 2)])
        min_length = {(0, 0): 0, (0, 1): 0}
        while q:
            at, level, color = q.popleft()
            for edge_color in range(2):
                if edge_color == color:
                    continue
                for to in edges[edge_color][at]:
                    if (to, edge_color) in min_length:
                        continue
                    min_length[to, edge_color] = level + 1
                    q.append((to, level + 1, edge_color))
        answer = [None] * n
        INF = float("inf")
        for i in range(n):
            answer[i] = min(min_length.get((i, 0), INF), min_length.get((i, 1), INF))
            if answer[i] == INF:
                answer[i] = -1
        return answer