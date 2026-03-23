class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, low = 0, prices[0]
        for p in prices:
            if (diff := p - low) >= 0:
                ans = diff if diff > ans else ans
            else:
                low = p
        return ans
