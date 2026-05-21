class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        prefix = list(accumulate(1 if n else -1 for n in possible))
        total = prefix[-1]
        for i in range(len(prefix) - 1):
            if 2 * prefix[i] > total:
                return i + 1
        return -1
