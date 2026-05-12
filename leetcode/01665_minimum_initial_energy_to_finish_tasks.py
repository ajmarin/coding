class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[0] - x[1])
        ans = energy = 0
        for cost, start in tasks:
            if energy <= start:
                ans += start - energy
                energy = start - cost
            else:
                energy -= cost
        return ans
