class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        ans = longest = prev = 0
        for employee, end in logs:
            duration = end - prev
            if duration > longest or duration == longest and employee < ans:
                longest = duration
                ans = employee
            prev = end
        return ans
