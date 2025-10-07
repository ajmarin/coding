class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        ans = [-1] * len(rains)
        drain_days = SortedList()
        full = {}
        for i, n in enumerate(rains):
            if n == 0:
                drain_days.add(i)
                ans[i] = 1
                continue
            if n in full:  # Gotta drain
                index = drain_days.bisect_left(full[n])
                if index == len(drain_days):
                    return []
                day = drain_days.pop(index)
                ans[day] = n
            full[n] = i
        return ans
