class Solution:
    def minimumCost(
        self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]
    ) -> int:
        hsum, vsum = sum(horizontalCut), sum(verticalCut)
        if not hsum or not vsum:
            return hsum + vsum
        heapify_max(horizontalCut)
        heapify_max(verticalCut)
        htop, vtop = heappop_max(horizontalCut), heappop_max(verticalCut)
        ans = 0
        while htop and vtop:
            if htop > vtop:
                ans += htop + vsum
                hsum -= htop
                htop = heappop_max(horizontalCut) if horizontalCut else 0
            else:
                ans += vtop + hsum
                vsum -= vtop
                vtop = heappop_max(verticalCut) if verticalCut else 0
        return ans + hsum + vsum
