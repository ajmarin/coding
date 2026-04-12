class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        bought, sold = -inf, 0
        for p in prices:
            bought, sold = (
                sold - p if sold - p > bought else bought,
                bought + p - fee if bought + p - fee > sold else sold,
            )
        return sold
