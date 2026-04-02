class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        start, end = rounds[0], rounds[-1]
        if start <= end:
            return [*range(start, end + 1)]
        return [*range(1, end + 1)] + [*range(start, n + 1)]
