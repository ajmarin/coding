class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        ans = 0
        for x in costs:
            if x > coins:
                break
            ans += 1
            coins -= x
        return ans
