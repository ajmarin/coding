class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        prev = 1 - groups[0]
        ans = []
        for i, g in enumerate(groups):
            if g != prev:
                ans.append(words[i])
            prev = g
        return ans
