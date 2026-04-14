class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        cnt, prev_cnt = 1, 0
        prev = inf
        for i, n in enumerate(nums):
            if n > prev:
                cnt += 1
            else:
                prev_cnt, cnt = cnt, 1
            if cnt == 2 * k or cnt >= k and prev_cnt >= k:
                return True
            prev = n
        return False
