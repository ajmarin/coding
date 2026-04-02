class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        return [
            next((p - d for d in prices[i + 1 :] if d <= p), p)
            for i, p in enumerate(prices)
        ]
