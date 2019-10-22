class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        candidate = [0, 1]
        count = [0, 0]
        for x in nums:
            if x == candidate[0]:
                count[0] += 1
            elif x == candidate[1]:
                count[1] += 1
            elif count[0] == 0:
                candidate[0], count[0] = x, 1
            elif count[1] == 0:
                candidate[1], count[1] = x, 1
            else:
                count = [c - 1 for c in count]
        return [x for x in candidate if nums.count(x) > len(nums) // 3]