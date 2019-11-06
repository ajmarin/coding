class Solution:
    def countArrangement(self, N: int) -> int:
        nums = [i for i in range(N + 1)]
        def tryPermute(index: int) -> int:
            if not index:
                return 1
            count = 0
            for i in range(index, 0, -1):
                nums[i], nums[index] = nums[index], nums[i]
                if not nums[index] % index or not index % nums[index]:
                    count += tryPermute(index - 1)
                nums[i], nums[index] = nums[index], nums[i]
            return count
        return tryPermute(N)