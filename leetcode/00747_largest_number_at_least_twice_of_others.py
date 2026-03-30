class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        biggest = index = second = 0
        for i, n in enumerate(nums):
            if n > biggest:
                second, biggest = biggest, n
                index = i
            elif n > second:
                second = n
        return index if biggest >= 2 * second else -1
