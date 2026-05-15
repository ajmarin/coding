class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        times = sorted(d / v for d, v in zip(dist, speed))
        return next((i for i, t in enumerate(times) if i >= t), len(dist))
