class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ones = [*accumulate([0] + [c == "1" for c in s])]
        if ones[-1] < k:
            return ""
        n = len(s)
        for l in range(1, n + 1):
            ans = min(
                (s[i : i + l] for i in range(n - l + 1) if ones[i + l] - ones[i] == k),
                default="",
            )
            if ans:
                return ans
