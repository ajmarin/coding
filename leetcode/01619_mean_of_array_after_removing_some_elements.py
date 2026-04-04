class Solution:
    def trimMean(self, arr: List[int]) -> float:
        n = len(arr)
        arr.sort()
        five_pct = n // 20
        return sum(arr[five_pct:-five_pct]) / (n - 2 * five_pct)
