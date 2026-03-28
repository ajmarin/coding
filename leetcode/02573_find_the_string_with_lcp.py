class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        ans = [""] * n
        curr = 0
        for i in range(n):
            if not ans[i]:
                if curr >= 26:
                    return ""
                char = ans[i] = chr(curr + ord("a"))
                for j in range(i + 1, n):
                    if lcp[i][j]:
                        ans[j] = char
                curr += 1

        for i in range(n):
            for j in range(n):
                if ans[i] != ans[j]:
                    if lcp[i][j]:
                        return ""
                elif i == n - 1 or j == n - 1:
                    if lcp[i][j] != 1:
                        return ""
                elif lcp[i][j] != lcp[i + 1][j + 1] + 1:
                    return ""
        return "".join(ans)
