class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        counts = Counter(map(tuple, grid))
        return sum(counts[col] for col in zip(*grid))
