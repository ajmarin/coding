class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        def test(totalTime: int) -> bool:
            t = totalTime * 8
            height = mountainHeight
            for w in workerTimes:
                reduction = math.floor((-1 + math.sqrt(1 + t / w)) / 2)
                height -= reduction
                if height <= 0:
                    break
            return height <= 0

        low, high = 0, 10**16
        while low < high:
            mid = (low + high) >> 1
            if test(mid):
                high = mid
            else:
                low = mid + 1
        return low
