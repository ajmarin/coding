class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        n = len(str1)
        m = len(str2)
        ans = ["a"] * (n + m - 1)
        free = [True] * (n + m - 1)
        for i, c1 in enumerate(str1):
            if c1 != "T":
                continue
            for j, c2 in zip(range(i, i + m), str2):
                if not free[j]:
                    if ans[j] != c2:
                        return ""
                    continue
                ans[j], free[j] = c2, False

        for i, c1 in enumerate(str1):
            if c1 != "F" or any(ans[j] != str2[j - i] for j in range(i, i + m)):
                continue
            j = next((j for j in reversed(range(i, i + m)) if free[j]), None)
            if j is None:
                return ""
            ans[j] = "b"
        return "".join(ans)
