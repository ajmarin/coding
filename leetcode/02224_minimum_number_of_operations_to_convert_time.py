def get_hours_and_minutes(time_str):
    return [int(part) for part in time_str.split(":")]


class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        now_h, now_m = get_hours_and_minutes(current)
        goal_h, goal_m = get_hours_and_minutes(correct)
        hour_diff = goal_h - now_h
        minutes_diff = goal_m - now_m
        if minutes_diff < 0:
            minutes_diff += 60
            hour_diff -= 1
        if hour_diff < 0:
            hour_diff += 24
        minutes_op = minutes_diff // 15
        minutes_diff %= 15
        minutes_op += minutes_diff // 5 + (minutes_diff % 5)
        return hour_diff + minutes_op
