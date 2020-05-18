class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = deque()
        lenp = len(p)
        c = Counter(p)
        goal = len(c)
        for i, x in enumerate(s):
            goal -= (c[x] == 1) - (c[x] == 0)
            c[x] -= 1
            offset = i - lenp
            if offset >= 0:
                x = s[offset]
                goal -= (c[x] == -1) - (c[x] == 0)
                c[x] += 1
            if not goal:
                ans.append(offset + 1)
        return ans