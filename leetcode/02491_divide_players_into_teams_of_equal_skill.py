class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        mid = len(skill) >> 1
        goal = skill[0] + skill[-1]
        ans = 0
        for a, b in zip(skill[:mid], skill[-1 : mid - 1 : -1]):
            if a + b != goal:
                return -1
            ans += a * b
        return ans
