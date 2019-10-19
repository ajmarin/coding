class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        n = len(nums)
        for i in range(1<<n):
            subset = []
            ii = i
            index = 0
            while ii:
                if ii & 1:
                    subset.append(nums[index])
                index += 1
                ii >>= 1
            answer.append(subset)
        return answer