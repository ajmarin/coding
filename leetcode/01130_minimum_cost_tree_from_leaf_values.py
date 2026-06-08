class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        ans = 0
        s = [30]
        for n in arr:
            while s[-1] <= n:
                ans += s.pop() * (n if n < s[-1] else s[-1])
            s.append(n)
        while len(s) > 2:
            ans += s.pop() * s[-1]
        return ans
