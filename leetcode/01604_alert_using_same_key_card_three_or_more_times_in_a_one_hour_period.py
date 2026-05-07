class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        times = defaultdict(list)
        for name, time in zip(keyName, keyTime):
            times[name].append(60 * int(time[:2]) + int(time[3:]))

        alerted = []
        for name in times:
            t = sorted(times[name])
            if any(b - a <= 60 for a, b in zip(t, t[2:])):
                alerted.append(name)
        return sorted(alerted)
