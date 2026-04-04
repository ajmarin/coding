class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        before, after = 0, n - 1
        ans = 0
        for n in arr:
            even_before = 1 + (before >> 1)
            odd_before = (before + 1) >> 1
            even_after = 1 + (after >> 1)
            odd_after = (after + 1) >> 1
            ans += n * (odd_before * odd_after + even_before * even_after)
            before += 1
            after -= 1
        return ans
