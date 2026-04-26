class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        exclusive_time = [0] * n
        stack = []
        for log in logs:
            fn, start_or_end, when = log.split(":")
            fn, when = int(fn), int(when)
            if stack:
                exclusive_time[stack[-1]] += when - prev
            if start_or_end == "start":
                stack.append(fn)
                prev = when
            else:
                if stack[-1] == fn:
                    exclusive_time[stack[-1]] += 1
                stack.pop()
                prev = when + 1
        return exclusive_time
