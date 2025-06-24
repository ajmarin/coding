class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        matches = [index for index, num in enumerate(nums) if num == key]
        ans = []
        low = 0
        for at in matches:
            high = min(at + k + 1, n)
            for index in range(max(low, at - k), high):
                ans.append(index)
            low = high
        return ans

