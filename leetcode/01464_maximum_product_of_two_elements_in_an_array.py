class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        biggest, second = -1, -1
        for n in nums:
            if n > biggest:
                biggest, second = n, biggest
            elif n > second:
                second = n
        return (biggest - 1) * (second - 1)
