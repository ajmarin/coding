class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        handled = [0] * k
        available, next_free = [*range(k)], []

        for i, t in enumerate(arrival):
            while next_free and t >= next_free[0][0]:
                s = heappop(next_free)[1]
                heappush(available, i + (s - i) % k)
            if not available:
                continue
            s = heappop(available) % k
            handled[s] += 1
            heappush(next_free, (t + load[i], s))

        most = max(handled)
        return [*filter(lambda i: handled[i] == most, range(k))]
