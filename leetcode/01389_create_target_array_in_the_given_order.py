class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        result = []
        for index, value in zip(index, nums):
            result.insert(index, value)
        return result    

