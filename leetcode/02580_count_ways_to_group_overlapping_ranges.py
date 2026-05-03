class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        groups, end = 0, -1
        for r in ranges:
            groups += r[0] > end
            end = r[1] if r[1] > end else end
        return pow(2, groups, mod=10**9 + 7)
