class Solution:
    def mergeSimilarItems(
        self, items1: List[List[int]], items2: List[List[int]]
    ) -> List[List[int]]:
        c = Counter()
        for v, w in items1:
            c[v] += w
        for v, w in items2:
            c[v] += w
        return sorted(c.items())
