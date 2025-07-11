class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        counts = Counter()
        free_rooms = list(range(n))
        running = []

        meetings.sort()
        most_meetings = win_room = 0
        for start, end in meetings:
            dur = end - start
            while running and running[0][0] <= start:
                heappush(free_rooms, heappop(running)[1])
            if free_rooms: room = heappop(free_rooms)
            else:
                endtime, room = heappop(running)
                end = endtime + dur
            heappush(running, (end, room))
            cnt = counts[room] + 1
            counts[room] = cnt
            if cnt > most_meetings or (cnt == most_meetings and room < win_room):
                most_meetings = cnt
                win_room = room
        return win_room

