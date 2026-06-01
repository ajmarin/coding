class Solution:
    def countArrays(self, original: List[int], bounds: List[List[int]]) -> int:
        n = len(original)
        low, high = bounds[0]
        for i in range(1, n):
            diff = original[i] - original[i - 1]
            cand_low, cand_high = bounds[i]
            low = low + diff if low + diff > cand_low else cand_low
            high = high + diff if high + diff < cand_high else cand_high
            if high < low:
                break
        return max(high - low + 1, 0)
