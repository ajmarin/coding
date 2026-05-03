class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        mod_count = [0] * 24
        ans = 0
        for h in hours:
            mod = h % 24
            ans += mod_count[24 - mod if mod else 0]
            mod_count[mod] += 1
        return ans
