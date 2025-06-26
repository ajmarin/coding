class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n, dire, radiant = len(senate), deque(), deque()
        for i, c in enumerate(senate):
            q = dire if c == 'D' else radiant
            q.append(i)
        while dire and radiant:
            d, r = dire.popleft(), radiant.popleft()
            dire.append(d + n) if d < r else radiant.append(r + n)
        return "Dire" if dire else "Radiant"

