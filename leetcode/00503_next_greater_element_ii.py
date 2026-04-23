class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        s = []
        ans = [-1] * len(nums)
        for i, num in enumerate(nums + nums):
            while s and nums[s[-1] % n] < num:
                ans[s.pop() % n] = num
            s.append(i)
        return ans
