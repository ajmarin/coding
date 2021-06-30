class Solution:
    def trap(self, height: List[int]) -> int:
        base_area = sum(height)
        l = height
        r = height[::-1]
        n = len(height)
        lmax, rmax = 0, 0
        for i in range(n):
            lmax = l[i] = max(l[i], lmax)
            rmax = r[i] = max(r[i], rmax)
        return sum(map(min, zip(l, r[::-1]))) - base_area

