class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        seen_key = [False] * n
        keys = deque([0])
        while keys:
            k = keys.popleft()
            if seen_key[k]: continue
            seen_key[k] = True
            keys.extend(rooms[k])
            n -= 1
        return n == 0

