class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        ans = total = 0
        for n in nums:
            total += n
            if total <= 0:
                break
            ans += 1
        return ans
