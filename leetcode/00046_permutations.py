class Solution:
    def solve(self, nums: List[int], current: List[int], solutions: List[List[int]]) -> None:
        if not nums:
            solutions.append(current)
            return
        for i in range(len(nums)):
            self.solve(nums[0:i] + nums[i + 1:], current + [nums[i]], solutions)
        
    def permute(self, nums: List[int]) -> List[List[int]]:
        solutions = []
        self.solve(nums, [], solutions)
        return solutions