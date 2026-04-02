class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        kth_missing = 0
        for n in arr:
            if kth_missing + k < n:
                return kth_missing + k
            k -= n - kth_missing
            kth_missing = n + 1
        return kth_missing + k
