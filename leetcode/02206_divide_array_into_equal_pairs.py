class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        return all(count % 2 == 0 for count in Counter(nums).values())
