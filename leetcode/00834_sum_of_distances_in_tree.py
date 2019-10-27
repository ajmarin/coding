class Solution:
    def sumOfDistancesInTree(self, N: int, edges: List[List[int]]) -> List[int]:
        graph = [collections.deque() for _ in range(N)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        ans = [None] * N
        def dfs(node: int, parent: int) -> (int, int):
            dsum, node_count = 0, 1
            for child in graph[node]:
                if child == parent:
                    continue
                child_dsum, child_node_count = dfs(child, node)
                dsum += child_dsum + child_node_count
                node_count += child_node_count
            ans[node] = dsum, node_count
            return ans[node]
        def dfs2(node: int, parent: int) -> None:
            ans[node] = ans[parent] + N - 2 * ans[node][1] if parent != -1 else ans[node][0]
            for child in graph[node]:
                if child != parent:
                    dfs2(child, node)
        dfs(0, -1)
        dfs2(0, -1)
        return ans