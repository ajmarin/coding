class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        c = collections.Counter(map(lambda t: t % 60, time))
        tri = lambda x: x * (x - 1) // 2
        return tri(c[0]) + tri(c[30]) + sum((c[x] * c[60 - x]) for x in range(1, 30))