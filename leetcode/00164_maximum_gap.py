class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        maxn = max(nums)
        minn = min(nums)
        bucket_size = (maxn - minn) // (n - 1) or 1
        bucket_count = 1 + (maxn - minn) // bucket_size
        buckets = [[float("inf"),float("-inf")] for i in range(bucket_count + 1)]
        for x in nums:
            bucket = buckets[(x - minn) // bucket_size]
            bucket[0] = min(bucket[0], x)
            bucket[1] = max(bucket[1], x)
        max_diff = 0
        last_bucket_max = minn
        for b in buckets:
            if b[0] == float("inf"):
                continue
            max_diff = max(max_diff, b[0] - last_bucket_max)
            last_bucket_max = b[1]
        return max_diff