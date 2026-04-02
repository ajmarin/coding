MONTHS = [
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
]


class Solution:
    def reformatDate(self, date: str) -> str:
        d, m, y = date.split(" ")
        return f"{int(y):04d}-{1 + MONTHS.index(m):02d}-{int(d[:-2]):02d}"
