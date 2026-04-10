class Solution:
    def lastVisitedIntegers(self, nums: List[int]) -> List[int]:
        ans, seen = [], deque([])
        minus_ones = 0
        for n in nums:
            if n > 0:
                seen.appendleft(n)
                minus_ones = 0
            else:
                ans.append(seen[minus_ones] if minus_ones < len(seen) else -1)
                minus_ones += 1
        return ans
