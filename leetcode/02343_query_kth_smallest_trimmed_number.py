class Solution:
    def smallestTrimmedNumbers(
        self, nums: List[str], queries: List[List[int]]
    ) -> List[int]:
        n = len(nums)
        return [
            sorted(range(n), key=lambda i: nums[i][-trim:])[k - 1]
            for k, trim in queries
        ]
