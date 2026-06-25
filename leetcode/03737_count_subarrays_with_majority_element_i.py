class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        ans = 0
        for s in range(n):
            count = 0
            for e in range(s, n):
                count += 1 if nums[e] == target else -1
                ans += count > 0
        return ans
