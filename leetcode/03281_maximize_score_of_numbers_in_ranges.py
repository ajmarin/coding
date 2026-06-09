class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        start.sort()

        def test(k: int) -> bool:
            curr = start[0] - k
            for s in start:
                curr += k
                if curr > s + d:
                    return False
                curr = s if s > curr else curr
            return True

        low, high = 0, 1 + (start[-1] + d - start[0]) // (len(start) - 1)
        while low < high:
            mid = (low + high) >> 1
            if test(mid):
                low = mid + 1
            else:
                high = mid
        return low - 1
