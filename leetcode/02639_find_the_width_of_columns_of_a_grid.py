def get_length(n: int) -> int:
    res = +(n == 0)
    if n < 0:
        res = 1
        n = -n
    while n:
        res += 1
        n //= 10
    return res


class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        ans = []
        for col in zip(*grid):
            ans.append(max(get_length(num) for num in col))
        return ans
