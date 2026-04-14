class Solution:
    def minDeletion(self, s: str, k: int) -> int:
        c = Counter(s)
        n = len(c)
        if n <= k:
            return 0
        to_delete = sorted(c.items(), key=itemgetter(1))
        return sum(td[1] for td in to_delete[: n - k])
