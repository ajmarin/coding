class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        low, high = 0, n + 1
        while low < high:
            mid = (low + high) >> 1
            if n - bisect_left(citations, mid) >= mid:
                low = mid + 1
            else:
                high = mid
        return low - 1
