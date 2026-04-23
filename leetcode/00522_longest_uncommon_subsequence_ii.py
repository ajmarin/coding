def is_subsequence(s: str, t: str):
    itert = iter(t)
    return all(c in itert for c in s)


class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        strs.sort(key=lambda s: -len(s))
        n = len(strs)
        for i in range(n):
            si = strs[i]
            if not any(is_subsequence(si, strs[j]) for j in range(n) if j != i):
                return len(si)
        return -1
