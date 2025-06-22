class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, low = 1, nums[0]
        for n in nums:
            if n - low > k:
                ans += 1
                low = n
        return ans


