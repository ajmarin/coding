class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)

        biggest_until = [None] * n
        biggest_until[0] = nums[0]
        for i in range(1, n):
            biggest_until[i] = max(biggest_until[i - 1], nums[i])

        smallest_after = [None] * n
        smallest_after[-1] = 10**7
        for i in range(n - 1, 0, -1):
            smallest_after[i - 1] = min(smallest_after[i], nums[i])

        for i, big in enumerate(biggest_until):
            if big <= smallest_after[i]:
                return i + 1
        return -1

