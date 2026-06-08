class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda p: p[1])
        chain = 0
        prev = -1001
        for left, right in pairs:
            if prev < left:
                prev = right
                chain += 1
        return chain
