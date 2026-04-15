class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)

        @cache
        def bt(index: int) -> int:
            if index > n:
                return 0
            if index == n:
                return 1
            if s[index] == "0":
                return 0
            return bt(index + 1) + (
                bt(index + 2) if s[index : index + 2] <= "26" else 0
            )

        return bt(0)
