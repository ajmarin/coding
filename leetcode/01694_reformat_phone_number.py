class Solution:
    def reformatNumber(self, number: str) -> str:
        cleaned = number.replace(" ", "").replace("-", "")
        ans = []
        i, remaining = 0, len(cleaned)
        while remaining > 4:
            ans.append(cleaned[i : i + 3])
            remaining -= 3
            i += 3
        if remaining == 4:
            ans.append(cleaned[i : i + 2])
            ans.append(cleaned[-2:])
        else:
            ans.append(cleaned[-remaining:])
        return "-".join(ans)
