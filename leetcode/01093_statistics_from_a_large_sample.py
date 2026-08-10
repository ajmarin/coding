class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        total = sum(count)
        half = total / 2
        curr = 0
        for i in range(256):
            curr += count[i]
            if curr >= half:
                break
        median = (
            i
            if curr > half
            else (i + next(x for x in range(i + 1, 256) if count[x])) / 2
        )
        return [
            next(i for i in range(256) if count[i]),
            next(i for i in range(255, -1, -1) if count[i]),
            sum(i * count[i] for i in range(256)) / total,
            median,
            max(range(256), key=count.__getitem__),
        ]
