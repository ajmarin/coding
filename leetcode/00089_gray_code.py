class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [x ^ (x >> 1) for x in range(1<<n)]