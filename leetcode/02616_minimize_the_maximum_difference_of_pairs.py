class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()

        def count(diff):
            count, skip = 0, 0
            for i, n in enumerate(nums[:-1]):
                if skip:
                    skip = 0
                    continue
                skip = nums[i + 1] - n <= diff
                count += skip
            return count

        left, right = 0, nums[-1] - nums[0] + 1
        while left < right:
            mid = (left + right) >> 1
            if count(mid) < p:
                left = mid + 1
            else:
                right = mid
        return left

