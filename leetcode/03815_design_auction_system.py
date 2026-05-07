class AuctionSystem:
    def __init__(self):
        self.bids = defaultdict(int)
        self.heaps = defaultdict(list)

    def addBid(self, userId: int, itemId: int, bidAmount: int) -> None:
        heappush_max(self.heaps[itemId], (bidAmount, userId))
        self.bids[userId, itemId] = bidAmount

    updateBid = addBid

    def removeBid(self, userId: int, itemId: int) -> None:
        del self.bids[userId, itemId]

    def getHighestBidder(self, itemId: int) -> int:
        h = self.heaps[itemId]
        while h:
            amount, userId = h[0]
            if self.bids[userId, itemId] == amount:
                return userId
            heappop_max(h)
        return -1
