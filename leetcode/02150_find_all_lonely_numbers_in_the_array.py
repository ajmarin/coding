class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        nums += [-10, 10**7]
        nums.sort()
        prev = nums[0]
        ans = []
        for i, n in enumerate(nums[1:-1], 1):
            if prev < n - 1 and nums[i + 1] > n + 1:
                ans.append(n)
            prev = n
        return ans
