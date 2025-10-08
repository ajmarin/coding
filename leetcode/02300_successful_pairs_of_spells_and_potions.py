class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        P = len(potions)
        potions.sort()
        return [P - bisect_left(potions, success / s) for s in spells]
