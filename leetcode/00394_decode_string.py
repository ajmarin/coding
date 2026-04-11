class Solution:
    def decodeString(self, s: str) -> str:
        ans = prev = ""
        nums, parts = [], []
        for c in s:
            if c.isdigit():
                if not prev.isdigit():
                    nums.append(0)
                nums[-1] = 10 * nums[-1] + int(c)
            elif c == "[":
                parts.append("")
            elif c == "]":
                part = parts.pop()
                num = nums.pop()
                if parts:
                    parts[-1] += num * part
                else:
                    ans += num * part
            elif parts:
                parts[-1] += c
            else:
                ans += c
            prev = c
        return ans
