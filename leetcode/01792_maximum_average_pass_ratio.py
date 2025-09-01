class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        h = []
        total = 0
        compute_gain = lambda p, t: (t - p) / (t * (t + 1))
        for p, t in classes:
            total += p / t
            heappush(h, (-compute_gain(p, t), p, t))
        while extraStudents:
            gain, p, t = h[0]
            total -= gain
            extraStudents -= 1
            p, t = p + 1, t + 1
            heapreplace(h, (-compute_gain(p, t), p, t))
        return total / len(classes)

