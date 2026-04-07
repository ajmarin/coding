DAYS_IN_MONTH = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def to_day_of_year(date_str: str) -> int:
    month, day = [int(p) for p in date_str.split("-")]
    return sum(DAYS_IN_MONTH[: month - 1]) + day


class Solution:
    def countDaysTogether(
        self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
    ) -> int:
        if arriveBob > leaveAlice or arriveAlice > leaveBob:
            return 0
        start = max(arriveAlice, arriveBob)
        end = min(leaveAlice, leaveBob)
        return to_day_of_year(end) - to_day_of_year(start) + 1
