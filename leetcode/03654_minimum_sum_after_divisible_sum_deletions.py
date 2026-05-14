class Solution:
    def minArraySum(self, nums: List[int], k: int) -> int:
        last = {0: 0}
        prefix = [0] * (len(nums) + 1)
        for i, n in enumerate(nums, 1):
            prefix[i] = n + prefix[i - 1]
            pmodk = prefix[i] % k
            prefix[i] = min(prefix[i], prefix[last.get(pmodk, i)])
            last[pmodk] = i
        return prefix[-1]
