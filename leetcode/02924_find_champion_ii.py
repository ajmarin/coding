class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        deg = [0] * n
        for e in edges:
            deg[e[1]] += 1
        champion = -1
        for i in range(n):
            if not deg[i]:
                if champion != -1:
                    return -1
                champion = i
        return champion
