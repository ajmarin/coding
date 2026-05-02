class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        g = gcd(n, k)
        ans = 0
        for i in range(g):
            tmp = sorted(arr[i::g])
            ans += sum(tmp[~j] - tmp[j] for j in range(len(tmp) >> 1))
        return ans
