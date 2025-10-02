class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        drank = empty = numBottles
        while empty >= numExchange:
            empty -= numExchange - 1
            numExchange += 1
            drank += 1
        return drank
