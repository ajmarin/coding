class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        if arr == brr:
            return 0
        transf_cost = lambda: sum(abs(b - a) for a, b in zip(arr, brr))
        before = transf_cost()
        arr.sort()
        brr.sort()
        return min(before, k + transf_cost())
