DAYS_IN_MONTH = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def is_leap(year):
    return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0


class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        elapsed = sum(365 + is_leap(y) for y in range(1971, year))
        elapsed += sum(DAYS_IN_MONTH[: month - 1])
        elapsed += day
        elapsed += is_leap(year) and month > 2
        return [
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
        ][elapsed % 7]
