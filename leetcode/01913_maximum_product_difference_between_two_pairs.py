class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        biggest = second_biggest = -(10**6)
        smallest = second_smallest = 10**6
        for n in nums:
            if n > biggest:
                biggest, second_biggest = n, biggest
            elif n > second_biggest:
                second_biggest = n
            if n < smallest:
                smallest, second_smallest = n, smallest
            elif n < second_smallest:
                second_smallest = n
        return biggest * second_biggest - smallest * second_smallest
