class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k:
            return False
        nums.sort()
        c = Counter(nums)
        for x in nums:
            if not c[x]:
                continue
            for i in range(x, x + k):
                if not c[i]:
                    return False
                c[i] -= 1
        return True
