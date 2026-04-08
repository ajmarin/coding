class Solution:
    def pivotInteger(self, n: int) -> int:
        trin = n * (n + 1) // 2
        root = int(sqrt(trin))
        return root if root**2 == trin else -1
