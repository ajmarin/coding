class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        order = sorted(range(n), key=times.__getitem__)
        free = list(range(n))
        heapify(free)
        busy = []
        for index in order:
            arrive, leave = times[index]
            while busy and busy[0][0] <= arrive:
                heappush(free, heappop(busy)[1])
            sit_on = heappop(free)
            if index == targetFriend:
                return sit_on
            heappush(busy, (leave, sit_on))
