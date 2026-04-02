def is_leap(y):
    return (not y & 3 and y % 100 != 0) or y % 400 == 0


DAYS_IN_MONTH = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
LEAP_YEARS = [y for y in range(1971, 2101) if is_leap(y)]


def get_days(date: str):
    year, month, day = [*map(int, date.split("-"))]
    days = 365 * (year - 1971) + bisect_left(LEAP_YEARS, year)
    days += sum(DAYS_IN_MONTH[: month - 1])
    days += day + (month > 2 and is_leap(year))
    return days


class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        return abs(get_days(date2) - get_days(date1))
