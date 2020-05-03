import heapq
class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        rows = len(mat)
        cols = len(mat[0])
        seen = set()
        heap = [(sum(row[0] for row in mat), [0] * rows)]
        total = None
        for _ in range(k):
            total, idx = heapq.heappop(heap)
            for row, col in enumerate(idx):
                if col + 1 == cols:
                    continue
                nidx = idx.copy()
                nidx[row] = col + 1
                if tuple(nidx) in seen:
                    continue
                seen.add(tuple(nidx))
                ntotal = total - mat[row][col] + mat[row][col + 1]
                heapq.heappush(heap, (ntotal, nidx))
        return total