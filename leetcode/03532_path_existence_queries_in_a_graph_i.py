class Solution:
    def pathExistenceQueries(
        self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]
    ) -> List[bool]:
        groups = [0] * n
        g, prev = 0, groups[0]
        for i, x in enumerate(nums):
            g += x - prev > maxDiff
            groups[i] = g
            prev = x
        return [groups[u] == groups[v] for u, v in queries]
