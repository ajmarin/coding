class Solution:
    def countMonobit(self, n: int) -> int:
        return 1 + floor(log2(n + 1))
