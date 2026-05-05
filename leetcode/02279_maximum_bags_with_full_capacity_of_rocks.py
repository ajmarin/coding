class Solution:
    def maximumBags(
        self, capacity: List[int], rocks: List[int], additionalRocks: int
    ) -> int:
        filled, n = 0, len(capacity)
        for i in range(n):
            capacity[i] -= rocks[i]
        capacity.sort()
        for c in capacity:
            if c > additionalRocks:
                break
            filled += 1
            additionalRocks -= c
        return filled
