def is_swap(a: int, b: int) -> bool:
    ca, cb = [0] * 10, [0] * 10
    diffs = 0
    while a or b:
        da, db = a % 10, b % 10
        diffs += da != db
        if diffs > 2:
            return False
        ca[da] += 1
        cb[db] += 1
        a //= 10
        b //= 10
    return diffs <= 2 and sum(abs(a - b) for a, b in zip(ca, cb)) == 0


class Solution:
    def countPairs(self, nums: List[int]) -> int:
        return sum(is_swap(ni, nums[j]) for i, ni in enumerate(nums) for j in range(i))
