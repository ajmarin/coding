class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        c = Counter(nums)
        half_k = k >> 1
        ans = min(c[half_k], c[k - half_k]) if k & 1 else c[half_k] >> 1
        for num in c:
            if num < half_k:
                ans += min(c[num], c[k - num])
        return ans
