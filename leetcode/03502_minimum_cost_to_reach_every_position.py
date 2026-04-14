class Solution:
    def minCosts(self, cost: List[int]) -> List[int]:
        min_seen = inf
        ans = []
        for c in cost:
            if c < min_seen:
                min_seen = c
            ans.append(min_seen)
        return ans
