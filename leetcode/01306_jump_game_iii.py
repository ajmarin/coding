class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        viz = [False] * n

        def dfs(at):
            if at < 0 or at >= n or viz[at]:
                return False
            viz[at] = True
            j = arr[at]
            return not j or dfs(at + j) or dfs(at - j)

        return dfs(start)
