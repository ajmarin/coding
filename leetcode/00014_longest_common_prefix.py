class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        lcp = strs[0]
        for s in strs:
            while lcp:
                if s.startswith(lcp):
                    break
                lcp = lcp[:-1]
        return lcp