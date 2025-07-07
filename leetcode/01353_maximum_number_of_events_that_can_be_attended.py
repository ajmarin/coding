class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        i, n = 1, len(events)
        count = 0
        day = events[0][0]
        endtimes = [events[0][1]]
        while endtimes:
            # remove expired events
            while endtimes and endtimes[0] < day:
                heappop(endtimes)
            # add started events
            while i < n and events[i][0] <= day:
                heappush(endtimes, events[i][1])
                i += 1
            # attend event ending earliest
            if endtimes:
                count += 1
                attended = heappop(endtimes)
                day += 1
            # skip ahead to next event start time if no running events
            if not endtimes and i < n:
                day = events[i][0]
                heappush(endtimes, events[i][1])
                i += 1
        return count

