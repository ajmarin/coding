class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        ans = deque()
        left = right = nums[0]
        range_to_str = lambda l,r: f"{l}" if l == r else f"{l}->{r}"
        for n in nums:
            if n > right + 1:
                ans.append(range_to_str(left, right))
                left = n
            right = n
        ans.append(range_to_str(left, right))
        return ans