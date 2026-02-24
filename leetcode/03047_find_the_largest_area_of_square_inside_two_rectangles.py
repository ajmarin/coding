class Solution:
    def largestSquareArea(
        self, bottomLeft: List[List[int]], topRight: List[List[int]]
    ) -> int:
        n = len(bottomLeft)
        ans = 0
        for i in range(n):
            bli = bottomLeft[i]
            tri = topRight[i]
            for j in range(i + 1, n):
                xl = max(bli[0], bottomLeft[j][0])
                xr = min(tri[0], topRight[j][0])
                if xr <= xl:
                    continue
                yb = max(bli[1], bottomLeft[j][1])
                yt = min(tri[1], topRight[j][1])
                if yt <= yb:
                    continue
                dx, dy = xr - xl, yt - yb
                if dx < dy:
                    ans = ans if ans > dx else dx
                else:
                    ans = ans if ans > dy else dy
        return ans * ans
