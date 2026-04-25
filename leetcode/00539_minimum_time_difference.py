class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        seen = set()
        for tp in timePoints:
            hours, mins = [int(s) for s in tp.split(":")]
            total_mins = 60 * hours + mins
            if total_mins in seen:
                return 0
            seen.add(total_mins)

        mins = sorted(seen)
        ans = 1440 + mins[0] - mins[-1]
        for a, b in pairwise(mins):
            ans = b - a if b - a < ans else ans
        return ans
