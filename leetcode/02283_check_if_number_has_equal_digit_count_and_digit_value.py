class Solution:
    def digitCount(self, num: str) -> bool:
        cnt = Counter(num)
        return all(cnt[str(i)] == int(c) for i, c in enumerate(num))
