class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans, diff, length = 0, 50_000, 0
        prev = diff
        for n in nums + [diff]:
            curr_diff, prev = n - prev, n
            if curr_diff == diff:
                length += 1
            else:
                ans += length * (length - 1) // 2
                length = 1
                diff = curr_diff
        return ans
