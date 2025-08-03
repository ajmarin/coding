class Solution:
    def maxBalancedShipments(self, weight: List[int]) -> int:
        shipments = 0
        maxw = -1
        for n in weight:
            if n >= maxw: maxw = n
            else:
                shipments += 1
                maxw = -1
        return shipments

