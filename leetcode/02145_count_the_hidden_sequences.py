class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        lowest = highest = differences[0]
        s = 0
        for d in differences:
            s += d
            if s < lowest:
                lowest = s
            elif s > highest:
                highest = s
        return max(upper - max(highest, 0) - (lower - min(lowest, 0)) + 1, 0)
