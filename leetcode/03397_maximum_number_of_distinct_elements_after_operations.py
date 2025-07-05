class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k >= n:
            return n
        if k == 0:
            return len(set(nums))

        nums.sort()

        ans, curr_min = 0, ~k
        for n in nums:
            num = n - k
            if num <= curr_min:
                high = n + k
                num = curr_min + 1
                if num > high:
                    num = high
            if num > curr_min:
                ans += 1
                curr_min = num
        return ans

