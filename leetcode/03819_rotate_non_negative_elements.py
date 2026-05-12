class Solution:
    def rotateElements(self, nums: List[int], k: int) -> List[int]:
        pos, values = [], []
        for i, n in enumerate(nums):
            if n >= 0:
                pos.append(i)
                values.append(n)
        if len(values) < 2 or not (k := k % len(values)):
            return nums
        for i, v in zip(pos, values[k:] + values[:k]):
            nums[i] = v
        return nums
