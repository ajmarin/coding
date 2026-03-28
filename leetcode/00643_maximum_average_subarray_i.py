class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        best = running_sum = sum(nums[:k])
        left = 0
        for n in nums[k:]:
            running_sum += n - nums[left]
            left += 1
            best = running_sum if running_sum > best else best
        return best / k
