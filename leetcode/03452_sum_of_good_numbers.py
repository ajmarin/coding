class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def is_good(i: int, x: int) -> int:
            left = i - k
            if left >= 0 and x <= nums[left]:
                return False
            right = i + k
            if right < n and x <= nums[right]:
                return False
            return True

        return sum(x for i, x in enumerate(nums) if is_good(i, x))
