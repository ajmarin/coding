class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        return goal in iter(s[-i:] + s[:-i] for i in range(len(s)))
