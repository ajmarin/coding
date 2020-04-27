class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        nums.sort(reverse=True)
        total = sum(nums)
        if total % k:
            return False
        desired = total // k
        s = [0]*(1 << n)
        for i in range(n):
            x = 1 << i
            for j in range(1, 1 << n):
                if j & x:
                    s[j] = s[j^x] + nums[i]
        def solve(used: int, k: int) -> bool:
            if k == 0:
                return True
            for i in range(1, 1 << n):
                if i & used:
                    continue
                if s[i] == desired and solve(used ^ i, k - 1):
                    return True
            return False
        return solve(0, k)