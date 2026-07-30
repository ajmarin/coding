class Solution:
    def canReach(self, start: list[int], target: list[int]) -> bool:
        return (start[0] + start[1]) & 1 == (target[0] + target[1]) & 1
