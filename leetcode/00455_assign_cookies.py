class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        gi = 0
        for size in sorted(s):
            gi += size >= g[gi]
            if gi == len(g):
                break
        return gi