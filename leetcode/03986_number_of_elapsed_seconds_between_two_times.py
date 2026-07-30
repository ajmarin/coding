def to_sec(t: str):
    return 60 * (60 * int(t[:2]) + int(t[3:5])) + int(t[6:])


class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        return to_sec(endTime) - to_sec(startTime)
