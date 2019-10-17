class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        for start in range(len(haystack) - len(needle) + 1):
            if haystack[start:].startswith(needle):
                return start
        return -1