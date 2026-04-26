class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        c = Counter()
        best = pos = 0
        width = sum(wall[0])
        for w in wall:
            total = 0
            for n in w[:-1]:
                total += n
                c[total] += 1
                if c[total] > best:
                    best = c[total]
                    pos = total
        return len(wall) - c[pos]
