class Solution:
    def longestValidParentheses(self, s: str) -> int:
        open_index = [None] * len(s)
        parts = [None] * len(s)
        ni, np = 0, 0
        for i, c in enumerate(s):
            if c == '(':
                open_index[ni] = i
                ni += 1
            elif ni:
                ni -= 1
                part = [open_index[ni], i]
                while np and parts[np - 1][0] > part[0]:
                    np -= 1
                if np and parts[np - 1][1] + 1 == part[0]:
                    parts[np - 1][1] = part[1]
                else:
                    parts[np] = part
                    np += 1
        return 1 + max(end - start for start, end in parts[:np]) if np else 0