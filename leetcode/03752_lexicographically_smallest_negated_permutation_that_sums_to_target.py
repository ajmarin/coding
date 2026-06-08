class Solution:
    def lexSmallestNegatedPerm(self, n: int, target: int) -> List[int]:
        highest = n * (n + 1) >> 1
        if abs(target) > highest:
            return []
        delta = highest - target
        if delta & 1:
            return []
        delta >>= 1
        ans = [0] * n
        l, r = -1, n
        for i in range(n, 0, -1):
            if i > delta:
                ans[r := r - 1] = i
            else:
                ans[l := l + 1] = -i
                delta -= i
        return ans
