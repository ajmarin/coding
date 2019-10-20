class Solution:
    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        K += 1
        total = sum(sweetness)
        left, right = 0, 1 + total // K
        while left < right:
            mid = (left + right) >> 1
            count, piece = 0, 0
            for s in sweetness:
                piece += s
                if piece >= mid:
                    count += 1
                    piece = 0
            if count >= K:
                left = mid + 1
            else:
                right = mid
        return left - 1