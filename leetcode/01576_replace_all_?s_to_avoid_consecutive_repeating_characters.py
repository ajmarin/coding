FILLERS = {"a", "b", "c"}


class Solution:
    def modifyString(self, s: str) -> str:
        chars = list(s)
        last = len(chars) - 1
        for i, c in enumerate(chars):
            if c == "?":
                before = chars[i - 1] if i else "_"
                after = chars[i + 1] if i != last else "_"
                chars[i] = (FILLERS - {before, after}).pop()
        return "".join(chars)
