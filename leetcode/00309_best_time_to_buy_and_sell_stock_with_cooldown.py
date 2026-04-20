class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy, sell, cooldown = -inf, 0, 0
        for p in prices:
            tmp = sell
            sell = sell if sell > buy + p else buy + p
            buy = buy if buy > cooldown - p else cooldown - p
            cooldown = tmp
        return sell
