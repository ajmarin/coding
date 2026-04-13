class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        once, twice = set(), set()
        for n in nums:
            if n not in once:
                once.add(n)
            elif n not in twice:
                twice.add(n)
            else:
                return False
        return True
