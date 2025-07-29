class Solution:
    def canCross(self, stones: List[int]) -> bool:
        last = stones[-1]
        q = deque([(0, 0)])
        states = {s: set() for s in stones}
        while q:
            at, j = q.pop()
            low = at + j - 1
            for pos in (low, low + 1, low + 2):
                if pos == last: return True
                reached = states.get(pos)
                if reached is None: continue
                j = pos - at
                if j in reached: continue
                reached.add(j)
                q.append((pos, j))
        return False

