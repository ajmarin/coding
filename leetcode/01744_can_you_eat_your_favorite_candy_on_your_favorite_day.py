class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        acc = list(accumulate(candiesCount, initial=0))
        return [
            acc[index + 1] > day and acc[index] < (day + 1) * daily
            for index, day, daily in queries
        ]
