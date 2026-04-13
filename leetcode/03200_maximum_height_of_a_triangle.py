class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        def build_triangle(nums: List[int]) -> int:
            for row in range(1, 32):
                pos = row & 1
                if nums[pos] < row:
                    break
                nums[pos] -= row
            return row - 1

        return max(build_triangle([red, blue]), build_triangle([blue, red]))
