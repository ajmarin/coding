class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        n = len(colors)
        prev, succ = colors[-1], colors[0]
        colors = colors + [colors[0]]
        ans = 0
        for i in range(n):
            me, succ = succ, colors[i + 1]
            ans += prev != me != succ
            prev = me
        return ans
