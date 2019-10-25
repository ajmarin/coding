class Solution:
    # 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    DAYS_BEFORE = [0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
    def dayOfYear(self, date: str) -> int:
        y, m, d = map(int, date.split('-'))
        add_one_for_leap = m > 2 and not y % 4 and (y % 100 != 0 or not y % 400)
        return d + self.DAYS_BEFORE[m] + add_one_for_leap