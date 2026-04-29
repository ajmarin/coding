class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        nums.sort()
        prev = sub = 0
        for n in nums:
            if n == prev:
                continue
            prev = n
            if n > k:
                break
            k += 1
            sub += n
        return k * (k + 1) // 2 - sub
