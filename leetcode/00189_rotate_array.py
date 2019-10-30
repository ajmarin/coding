class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        start = 0
        start, n = 0, len(nums)
        k %= n
        while k:
            j = n - k
            for i in range(start, start + k):
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
            start += k
            k %= (n - start)