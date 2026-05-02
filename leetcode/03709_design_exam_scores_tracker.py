class ExamTracker:
    def __init__(self):
        self.times = [0]
        self.scores = [0]

    def record(self, time: int, score: int) -> None:
        self.times.append(time)
        self.scores.append(score + self.scores[-1])

    def totalScore(self, startTime: int, endTime: int) -> int:
        end_index = bisect_right(self.times, endTime) - 1
        start_index = bisect_left(self.times, startTime) - 1
        return self.scores[end_index] - self.scores[start_index]
