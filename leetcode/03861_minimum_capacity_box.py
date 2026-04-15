class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        index, min_cap = -1, inf
        for i, c in enumerate(capacity):
            if itemSize <= c < min_cap:
                index = i
                min_cap = c
        return index
