class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        prefix = list(accumulate(sorted(nums)))
        return [bisect_right(prefix, q) for q in queries]
