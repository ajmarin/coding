def digit_sum(n: int) -> int:
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res


class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        pos = {
            val: p
            for p, val in enumerate(sorted(nums, key=lambda n: (digit_sum(n), n)))
        }
        target = [pos[x] for x in nums]

        swaps = 0
        for i in range(len(nums)):
            while target[i] != i:
                j = target[i]
                target[i], target[j] = target[j], target[i]
                swaps += 1
        return swaps
