import itertools

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        iterators = [iter(nums)] * 3
        ans = list(itertools.zip_longest(*iterators))
        return ans if all(high - low <= k for low, _, high in ans) else []
