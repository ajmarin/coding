class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        c = Counter(nums)
        if k == 1:
            return max((n for n in nums if c[n] == 1), default=-1)
        elif k == len(nums):
            return max(nums)
        ans = nums[0] if c[nums[0]] == 1 else -1
        last = nums[-1]
        return last if last > ans and c[last] == 1 else ans
