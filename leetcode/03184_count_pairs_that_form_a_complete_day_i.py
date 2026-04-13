class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        c = Counter()
        ans = 0
        for h in hours:
            me = h % 24
            ans += c[24 - me if me else 0]
            c[me] += 1
        return ans
