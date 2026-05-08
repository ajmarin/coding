class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt = Counter(tasks)
        cmax = max_freq = 0
        for f in cnt.values():
            if f > max_freq:
                max_freq = f
                cmax = 0
            cmax += f == max_freq
        return max(len(tasks), (n + 1) * (max_freq - 1) + cmax)
