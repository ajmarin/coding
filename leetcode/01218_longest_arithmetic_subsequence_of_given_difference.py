class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        z = collections.defaultdict(int)
        for i in arr:
            z[i + difference] = z[i] + 1
        return max(z.values())