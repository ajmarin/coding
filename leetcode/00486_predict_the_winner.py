import functools
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        @functools.lru_cache(None)
        def bt(left: int, right: int, score: int, playing: int) -> bool:
            if left > right:
                return score
            if playing == 1:
                l = bt(left + 1, right, score + nums[left], 1 - playing)
                r = bt(left, right - 1, score + nums[right], 1 - playing)
                return max(l, r)
            else:
                l = bt(left + 1, right, score, 1 - playing)
                r = bt(left, right - 1, score, 1 - playing)
                return min(l, r)
        return 2 * bt(0, len(nums) - 1, 0, 1) >= sum(nums)