class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        def find_lis(arr: List[int]) -> int:
            ans = 1
            prev, size = -1, 0
            for n in arr:
                if n > prev:
                    size += 1
                else:
                    ans = size if size > ans else ans
                    size = 1
                prev = n
            return max(ans, size)

        return max(find_lis(nums), find_lis(nums[::-1]))
