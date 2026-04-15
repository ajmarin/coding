class Solution:
    def subsetsWithDup(self, nums: List[int], index=0, curr=None) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans, subset = [], []

        def bt(index: int):
            if index == n:
                ans.append(subset.copy())
                return

            curr = nums[index]
            subset.append(curr)
            bt(index + 1)
            subset.pop()

            while index + 1 < n and nums[index + 1] == curr:
                index += 1

            bt(index + 1)

        bt(0)
        return ans
