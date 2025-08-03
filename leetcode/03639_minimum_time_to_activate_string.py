class Solution:
    def minTime(self, s: str, order: List[int], k: int) -> int:
        N = len(s)
        ans = total = 0
        for num in order:
            after = s.find("*", num + 1)
            if after == -1: after = N
            before = s.rfind("*", 0, num)
            total += (num - before) * (after - num)
            s = s[:num] + '*' + s[num + 1:]
            if total >= k: return ans
            ans += 1
        return -1

