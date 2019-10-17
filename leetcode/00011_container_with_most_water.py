class Solution:
    def maxArea(self, height: List[int]) -> int:
        most_water = 0
        left = 0
        right = len(height) - 1
        while left < right:
            hl = height[left]
            hr = height[right]
            most_water = max(most_water, (right - left) * min(hl, hr))
            if hl < hr:
                left += 1
            else:
                right -= 1
        return most_water