class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        ans, parts = [], []

        def bt(index: int):
            if index >= n:
                if len(parts) == 4:
                    ans.append(".".join(parts))
                return
            if len(parts) == 4:
                return

            for end in range(index + 1, min(index + 4, n + 1)):
                part = s[index:end]
                if int(part) > 255:
                    break
                parts.append(part)
                bt(end)
                parts.pop()
                if s[index] == "0":
                    break

        bt(0)
        return ans
