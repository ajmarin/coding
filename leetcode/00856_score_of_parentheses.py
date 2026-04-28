class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        total, curr_value = 0, 1
        pos = []
        for i, c in enumerate(s):
            if c == "(":
                pos.append(i)
                curr_value <<= 1
            else:
                curr_value >>= 1
                if pos.pop() == i - 1:
                    total += curr_value
        return total
