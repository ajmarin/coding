class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        answer = 0
        for i, biggest in enumerate(nums[2:]):
            left, right = 0, i + 1
            num_left, num_right = nums[left], nums[right]
            while left < right:
                if num_left + num_right > biggest:
                    answer += right - left
                    right -= 1
                    num_right = nums[right]
                else:
                    left += 1
                    num_left = nums[left]
        return answer

