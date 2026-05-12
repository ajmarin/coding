class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        n = len(nums)

        def test(goal: int) -> bool:
            extra = 0
            for i in range(n - 1, 0, -1):
                extra += nums[i] - goal
                extra = 0 if extra < 0 else extra
            return nums[0] + extra <= goal

        low, high = nums[0], max(nums) + 1
        while low < high:
            mid = (low + high) >> 1
            if not test(mid):
                low = mid + 1
            else:
                high = mid
        return low
