class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda t: t[1])
        busy = 0
        dropoff = []
        for num, begin, end in trips:
            while dropoff and dropoff[0][0] <= begin:
                busy -= heappop(dropoff)[1]
            busy += num
            if busy > capacity:
                return False
            heappush(dropoff, (end, num))
        return True
