class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left, right = 1, max(time) * ((totalTrips + len(time) - 1) // len(time))
        while left <= right:
            elapsed = (left + right) >> 1
            if sum(elapsed // t for t in time) < totalTrips:
                left = elapsed + 1
            else:
                right = elapsed - 1
        return left

