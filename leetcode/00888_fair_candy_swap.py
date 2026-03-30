class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        diff = (sum(bobSizes) - sum(aliceSizes)) >> 1
        bob_set = set(bobSizes)
        return next([a, b] for a in aliceSizes if (b := a + diff) in bob_set)
