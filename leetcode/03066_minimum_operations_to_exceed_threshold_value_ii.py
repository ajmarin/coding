class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapify(nums)
        ops = 0
        while nums[0] < k:
            heapreplace(nums, 2 * heappop(nums) + nums[0])
            ops += 1
        return ops
