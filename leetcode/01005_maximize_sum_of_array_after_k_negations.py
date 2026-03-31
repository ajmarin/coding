class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        negative_indices = []
        total = 0
        for i, n in enumerate(nums):
            if n < 0:
                negative_indices.append(i)
            total += n
        negative_indices.sort(key=lambda i: nums[i])
        for i in negative_indices[:k]:
            nums[i] = -nums[i]
            total += nums[i] << 1
        remaining = max(k - len(negative_indices), 0)
        sub = 2 * min(nums) if remaining & 1 else 0
        return total - sub
