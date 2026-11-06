class Solution:
    def countServers(
        self, n: int, logs: List[List[int]], x: int, queries: List[int]
    ) -> List[int]:
        logs.append([0, 10**7])
        logs.sort(key=itemgetter(1))

        active = [0] * (n + 1)
        ans = [0] * len(queries)
        left_iter, right_iter = iter(logs), iter(logs)
        r_server, r_time = next(right_iter)
        l_server, l_time = next(left_iter)

        idle = n
        for i, t in sorted(enumerate(queries), key=itemgetter(1)):
            while r_time <= t:
                idle -= not active[r_server]
                active[r_server] += 1
                r_server, r_time = next(right_iter)
            start = t - x
            while l_time < start:
                active[l_server] -= 1
                idle += not active[l_server]
                l_server, l_time = next(left_iter)
            ans[i] = idle
        return ans
