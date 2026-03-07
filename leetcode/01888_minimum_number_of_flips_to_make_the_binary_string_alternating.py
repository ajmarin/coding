class Solution:
    def minFlips(self, s: str) -> int:
        N = len(s)
        pre = [[0, 0] for _ in range(N)]
        pre[0][s[0] == "0"] = 1

        for i in range(1, N):
            pre[i][0] = pre[i - 1][1] + (s[i] == "1")
            pre[i][1] = pre[i - 1][0] + (s[i] == "0")

        ans = min(pre[-1])
        if not N & 1:
            return ans

        suf = [[0, 0] for _ in range(N)]
        suf[N - 1][s[-1] == "0"] = 1

        for i in range(N - 2, -1, -1):
            suf[i][0] = suf[i + 1][1] + (s[i] == "1")
            suf[i][1] = suf[i + 1][0] + (s[i] == "0")

        for i in range(N - 1):
            for d in (0, 1):
                c = pre[i][d] + suf[i + 1][d]
                ans = ans if ans < c else c

        return ans
