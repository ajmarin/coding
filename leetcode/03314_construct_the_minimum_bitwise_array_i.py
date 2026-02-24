mapping = {}
for i in range(1000, -1, -1):
    mapping[i | (i + 1)] = i


class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        return [mapping.get(n, -1) for n in nums]
