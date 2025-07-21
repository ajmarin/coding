MOD = 10**9 + 7

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        y_counts = Counter(map(itemgetter(1), points))

        ans = pairs = 0
        for v in y_counts.values():
            if v == 1: continue
            me = v * (v - 1) // 2
            ans += me * pairs
            pairs += me
        return ans % MOD

