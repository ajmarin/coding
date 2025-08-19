class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans, cnt = 0, 0
        for n in chain(nums, [-1]):
            if n == 0: cnt += 1
            else:
                if cnt: ans += cnt * (cnt + 1)
                cnt = 0
        return ans >> 1

