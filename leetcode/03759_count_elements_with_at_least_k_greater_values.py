class Solution:
    def countElements(self, nums: List[int], k: int) -> int:
        c = Counter(nums)
        remaining = len(nums)
        ans = 0
        for n in sorted(c.keys()):
            remaining -= c[n]
            if remaining < k:
                break
            ans += c[n]
        return ans
