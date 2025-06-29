class Solution:
    def partitionString(self, s: str) -> List[str]:
        seen = set()
        curr = ""
        ans = []
        for c in s:
            curr += c
            if curr not in seen:
                seen.add(curr)
                ans.append(curr)
                curr = ""
        return ans

