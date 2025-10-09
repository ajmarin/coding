class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        N = len(skill)
        idle_by = [0] * N
        for m in mana:
            now = idle_by[0]
            for available, s in zip(idle_by, skill):
                now = (now if now > available else available) + m * s
            for i in range(N - 1, -1, -1):
                idle_by[i] = now
                now -= m * skill[i]
        return idle_by[-1]
