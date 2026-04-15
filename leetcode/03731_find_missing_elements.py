class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        present = [False] * 101
        maxn = minn = nums[0]
        for n in nums:
            present[n] = True
            if n > maxn:
                maxn = n
            elif n < minn:
                minn = n
        return [n for n in range(minn, maxn + 1) if not present[n]]
