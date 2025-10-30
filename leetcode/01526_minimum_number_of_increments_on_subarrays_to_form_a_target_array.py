class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ans = prev = 0
        for n in target:
            if n < prev:
                ans += prev - n
            prev = n
        return ans + prev
