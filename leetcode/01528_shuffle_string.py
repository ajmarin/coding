class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ans, iters = [None] * len(s), iter(s)
        for i in indices:
            ans[i] = next(iters)
        return "".join(ans)
