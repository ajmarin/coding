class Solution:
    def maxEnergyBoost(self, a: List[int], b: List[int]) -> int:
        a[1] += a[0]
        b[1] += b[0]
        pa = a[1]
        pb = b[1]
        for i in range(2, len(a)):
            a[i] = pa = a[i] + (pa if pa >= b[i - 2] else b[i - 2])
            b[i] = pb = b[i] + (pb if pb >= a[i - 2] else a[i - 2])
        return max(a[-1], b[-1])
