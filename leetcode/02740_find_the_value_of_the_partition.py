class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        low = 10**9
        prev = -low
        for n in nums:
            low = low if low < n - prev else n - prev
            prev = n
        return low
