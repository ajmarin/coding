class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        n = len(s)
        if n != len(goal):
            return False
        if s == goal:
            return any(v > 1 for v in Counter(s).values())

        c = list(s)
        left = next((i for i in range(n) if c[i] != goal[i]), n)
        right = next((i for i in range(n - 1, -1, -1) if c[i] != goal[i]), -1)
        if left > right:
            return False
        c[left], c[right] = c[right], c[left]
        return "".join(c) == goal
