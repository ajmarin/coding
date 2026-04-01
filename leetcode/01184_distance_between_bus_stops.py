class Solution:
    def distanceBetweenBusStops(
        self, distance: List[int], start: int, destination: int
    ) -> int:
        if start > destination:
            start, destination = destination, start
        partial = sum(distance[start:destination])
        return min(partial, sum(distance) - partial)
