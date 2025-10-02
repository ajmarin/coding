class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        drank = empty = numBottles
        while empty >= numExchange:
            exchanged = empty // numExchange
            drank += exchanged
            empty = empty - exchanged * (numExchange - 1)
        return drank
