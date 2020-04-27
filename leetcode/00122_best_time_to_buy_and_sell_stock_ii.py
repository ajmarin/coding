class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        answer = 0
        prev = prices[0]
        for price in prices:
            if price > prev:
                answer += price - prev
            prev = price    
        return answer