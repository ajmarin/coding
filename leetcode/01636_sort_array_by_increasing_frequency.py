class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        nums.sort(key=lambda n: (cnt[n], -n))
        return nums
