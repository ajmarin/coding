class Solution:
    def maxDepth(self, root: "Node") -> int:
        if root is None:
            return 0
        return 1 + max(map(self.maxDepth, root.children), default=0)
