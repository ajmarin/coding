class Solution:
    def toggleLightBulbs(self, bulbs: list[int]) -> list[int]:
        return sorted(n for n, c in Counter(bulbs).items() if c & 1)
