class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        heapify_max(gifts)
        for _ in range(k):
            heapreplace_max(gifts, int(sqrt(gifts[0])))
        return sum(gifts)
