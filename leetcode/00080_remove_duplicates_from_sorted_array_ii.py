class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        last_ins = None
        i, ins, rep = 0, 0, 0
        while i < len(nums):
            if nums[i] == last_ins:
                rep += 1
            else:
                rep = 1
                last_ins = nums[i]
            if rep <= 2:
                nums[ins] = nums[i]
                ins += 1
            i += 1
        return ins