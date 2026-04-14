class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        available = [True] * len(baskets)
        ans = 0
        for f in fruits:
            for i, (b, free) in enumerate(zip(baskets, available)):
                if free and b >= f:
                    available[i] = False
                    break
            else:
                ans += 1
        return ans
