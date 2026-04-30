class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)

        def get_bounds(start: int, stop: int, step: int):
            bounds, s = [0] * n, []
            for i in range(start, stop, step):
                num = nums
                while s and nums[s[-1]] >= nums[i]:
                    s.pop()
                bounds[i] = s[-1] + step if s else start
                s.append(i)
            return bounds

        prefix_sum = list(accumulate(nums, initial=0))
        return (
            max(
                nums[i] * (prefix_sum[right + 1] - prefix_sum[left])
                for i, (left, right) in enumerate(
                    zip(get_bounds(0, n, 1), get_bounds(n - 1, -1, -1))
                )
            )
            % 1_000_000_007
        )
