class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        biggest = max(candidates)
        ans, i = 1, 1
        while i <= biggest:
            ans = max(ans, sum(1 for num in candidates if num & i))
            i <<= 1
        return ans

