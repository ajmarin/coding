class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        return sum(startTime[i] <= queryTime <= endTime[i] for i in range(len(startTime)))