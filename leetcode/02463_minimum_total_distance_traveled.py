class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        r = len(robot) + 1
        robot.sort()
        factory.sort()
        prev, curr = [inf] * r, [inf] * r
        prev[0] = 0
        for pos, cap in factory:
            for prev_repaired in range(r):
                if prev[prev_repaired] == inf:
                    break
                prev_dist = prev[prev_repaired]
                dist = 0
                for repaired in range(min(cap + 1, r - prev_repaired)):
                    total_repaired = prev_repaired + repaired
                    if repaired:
                        dist += abs(robot[total_repaired - 1] - pos)
                    curr[total_repaired] = min(curr[total_repaired], prev_dist + dist)
            prev, curr = curr, prev
        return prev[r - 1]
