class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        power = list(map(sum, mat))
        return sorted(range(len(mat)), key=power.__getitem__)[:k]