class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def ship_it(capacity: int) -> int:
            curr, days = 0, 1
            for w in weights:
                curr += w
                if curr > capacity:
                    curr = w
                    days += 1
            return days

        low, high = max(weights), sum(weights) + 1
        while low < high:
            mid = (low + high) >> 1
            if ship_it(mid) > days:
                low = mid + 1
            else:
                high = mid
        return low
