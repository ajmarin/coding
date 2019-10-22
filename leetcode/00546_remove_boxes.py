import functools
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        @functools.lru_cache(None)
        def solve(l, r, k):
            if l > r:
                return 0
            bl = boxes[l]
            while l <= r and boxes[l] == bl:
                l, k = l + 1, k + 1
            res = k * k + solve(l, r, 0)
            for pivot in range(l, r + 1):
                if boxes[pivot] == bl:
                    res = max(res, solve(l, pivot - 1, 0) + solve(pivot, r, k))
            return res
        return solve(0, n - 1, 0)