class Solution:
    def numberOfRounds(self, loginTime: str, logoutTime: str) -> int:
        to_mins = lambda t: 60 * int(t[:2]) + int(t[3:])
        start, end = to_mins(loginTime), to_mins(logoutTime)
        if start % 15:
            start += 15 - start % 15
        if end % 15:
            end -= end % 15
        if logoutTime < loginTime:
            end += 1440
        return (end - start) // 15 if end > start else 0
