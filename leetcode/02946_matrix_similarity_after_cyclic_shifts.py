class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n = len(mat[0])
        return k % n == 0 or all(
            all(row[j] == row[(j + k) % n] for j in range(n)) for row in mat
        )
