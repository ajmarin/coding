class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zero = 0
        two = len(nums) - 1
        i = 0
        while i <= two:
            if nums[i] == 0:
                if zero < i:
                    nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1
            elif nums[i] == 2:
                if two > i:
                    nums[i], nums[two] = nums[two], nums[i]
                two -= 1
                i -= 1
            i += 1