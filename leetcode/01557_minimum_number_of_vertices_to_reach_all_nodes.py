class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        deg = [0] * n
        for e in edges:
            deg[e[1]] += 1
        return [i for i in range(n) if not deg[i]]
