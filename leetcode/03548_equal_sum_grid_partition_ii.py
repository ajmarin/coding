class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        row_sums = [*map(sum, grid)]
        cols = [*zip(*grid)]
        col_sums = [*map(sum, zip(*grid))]
        total = sum(row_sums)

        def test(matrix, sums):
            seen, curr_sum = set(), 0
            for nums, nums_sum in zip(matrix, sums):
                seen.update(nums)
                curr_sum += nums_sum
                diff = 2 * curr_sum - total
                if diff < 0:
                    continue
                if (
                    diff == 0
                    or diff == nums[-1]
                    or (
                        diff in seen
                        and nums_sum != curr_sum
                        and (len(nums) > 1 or diff in (nums[0], matrix[0][0]))
                    )
                ):
                    return True
            return False

        return (
            test(grid, row_sums)
            or test(cols, col_sums)
            or test(grid[::-1], row_sums[::-1])
            or test(cols[::-1], col_sums[::-1])
        )
