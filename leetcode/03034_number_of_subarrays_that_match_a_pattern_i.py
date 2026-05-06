compare = lambda a, b: (a < b) - (a > b)


class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        m = len(pattern)

        def matches_pattern(start: int) -> bool:
            prev = nums[start]
            for i, expected in enumerate(pattern, 1):
                curr = nums[start + i]
                res = compare(prev, curr)
                if res != expected:
                    return False
                prev = curr
            return True

        return sum(matches_pattern(s) for s in range(len(nums) - m))
