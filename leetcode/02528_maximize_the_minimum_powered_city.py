class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        N = len(stations)
        S = N + r

        def test(min_power: int) -> bool:
            used = extra = 0
            addl_stations = [0] * S
            for i in range(N):
                if i > r:
                    extra -= addl_stations[i - r - 1]
                missing = min_power - stations[i] - extra
                if missing <= 0:
                    continue
                addl_stations[i + r] = missing
                extra += missing
                if (used := used + missing) > k:
                    break
            return used <= k

        at = 0
        total = sum(stations[:r])
        tmp = [0] * r + stations + [0] * r
        for n in tmp[2 * r :]:
            total += n
            stations[at] = total
            total -= tmp[at]
            at += 1

        low = min(stations)
        high = max(stations) + k + 1
        while low <= high:
            mid = (low + high) >> 1
            if test(mid):
                low = mid + 1
            else:
                high = mid - 1
        return low - 1
