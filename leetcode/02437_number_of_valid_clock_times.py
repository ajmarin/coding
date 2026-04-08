class Solution:
    def countTime(self, time: str) -> int:
        hours = minutes = 1
        if time.startswith("??"):
            hours = 24
        elif time[0] == "?":
            hours = 2 + (time[1] <= "3")
        elif time[1] == "?":
            hours = 10 if time[0] != "2" else 4

        if time[3] == "?":
            minutes *= 6
        if time[4] == "?":
            minutes *= 10
        return hours * minutes
