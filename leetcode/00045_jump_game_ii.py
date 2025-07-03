class Solution:
    def jump(self, nums: List[int]) -> int:
        at, furthest, jumps = 0, 0, 0
        for i, n in enumerate(nums[:-1]):
            cand = i + n
            furthest = cand if cand > furthest else furthest
            if i == at:
                jumps += 1
                at = furthest
        return jumps

