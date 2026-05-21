def solve(arr, wanted, zeroes, ones) -> int:
    arr = arr.copy()
    indices = [zeroes[:], ones[:]]
    cost = 0
    for i in range(len(arr) - 1, -1, -1):
        if arr[i] != wanted:
            idx = indices[wanted]
            while idx and idx[-1] >= i:
                idx.pop()
            if not idx:
                return inf
            j = idx.pop()
            cost += i - j
            arr[i], arr[j] = arr[j], arr[i]
        wanted ^= 1
    return cost


class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        if abs(len(nums) - 2 * sum(n & 1 for n in nums)) > 1:
            return -1
        zeroes, ones = [], []
        for i, n in enumerate(nums):
            nums[i] = n & 1
            (ones if n & 1 else zeroes).append(i)
        return min(solve(nums, start, zeroes, ones) for start in (0, 1))
