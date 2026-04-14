class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        c = Counter(nums)
        repeated = sum(cnt > 1 for cnt in c.values())
        left = rounds = 0
        while repeated:
            rounds += 1
            for _ in range(3):
                n = nums[left]
                left += 1
                c[n] -= 1
                repeated -= c[n] == 1
                if left == len(nums):
                    break
        return rounds
