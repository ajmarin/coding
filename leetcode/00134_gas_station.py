class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        deficit = start = tank = 0
        for i in range(len(gas)):
            tank += gas[i] - cost[i]
            if tank < 0:
                deficit -= tank
                tank = 0
                start = i + 1
        return start if tank - deficit >= 0 else -1
