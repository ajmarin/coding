class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        good = n * (n + 1) >> 1
        left, pairs = -1, 0
        cnt = {}
        for right, x in enumerate(nums):
            if x in cnt:
                pairs += cnt[x]
                cnt[x] += 1
            else:
                cnt[x] = 1
            while pairs >= k:
                rem = nums[left := left + 1]
                cnt[rem] -= 1
                pairs -= cnt[rem]
            good -= right - left
        return good
