class Solution:
    def maxDifference(self, s: str) -> int:
        maxodd, mineven = 0, 100
        for a, cnt in Counter(s).items():
            if cnt & 1:
                maxodd = cnt if cnt > maxodd else maxodd
            else:
                mineven = cnt if cnt < mineven else mineven
        return maxodd - mineven

