class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[-1] == "1" or "1" * maxJump in s:
            return False

        reachable = deque([0])
        for i, c in enumerate(s[1:], 1):
            if c == "1":
                continue
            lowest = i - maxJump
            while reachable and reachable[0] < lowest:
                reachable.popleft()
            if not reachable:
                break
            if reachable[0] + minJump <= i:
                reachable.append(i)
        return len(reachable) > 0 and reachable[-1] == len(s) - 1
