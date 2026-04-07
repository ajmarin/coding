class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        last = [-1] * 26
        for i, c in enumerate(s):
            ordc = ord(c) - ord("a")
            if last[ordc] != -1 and i - last[ordc] != distance[ordc]:
                return False
            last[ordc] = i + 1
        return True
