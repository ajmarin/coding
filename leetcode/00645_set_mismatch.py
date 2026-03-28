class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        c = Counter(nums)
        return [
            next(n for n in range(1, 1 + len(nums)) if c[n] == 2),
            next(n for n in range(1, 1 + len(nums)) if c[n] == 0),
        ]
