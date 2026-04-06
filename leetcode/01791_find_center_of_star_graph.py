class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return next(x for x in edges[1] if x in edges[0])
