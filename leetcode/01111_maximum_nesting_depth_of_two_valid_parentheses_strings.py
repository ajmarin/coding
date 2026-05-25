class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = []
        depth = 1
        for c in seq:
            depth ^= c == "("
            ans.append(depth & 1)
            depth ^= c == ")"
        return ans
