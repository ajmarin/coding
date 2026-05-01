class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        mapping = {str(i): str((i + a) % 10) for i in range(10)}

        def add(s: str):
            res = ""
            for i in range(n):
                res += mapping[s[i]] if i & 1 else s[i]
            return res

        visited = set()

        def dfs(digits: str):
            if digits in visited:
                return
            visited.add(digits)
            dfs(digits[-b:] + digits[:-b])
            dfs(add(digits))

        dfs(s)
        return "".join(map(str, min(visited)))
