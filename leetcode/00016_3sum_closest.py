class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        min_diff = float("+inf")
        best = 0
        for i in range(n - 2):
            j = i + 1
            k = n - 1
            total = nums[i] + nums[j] + nums[k]
            while j < k:
                abs_diff = abs(total - target)
                if abs_diff < min_diff:
                    min_diff = abs_diff
                    best = total
                if total > target:
                    total += nums[k - 1] - nums[k]
                    k -= 1
                else:
                    total += nums[j + 1] - nums[j]
                    j += 1
        return best