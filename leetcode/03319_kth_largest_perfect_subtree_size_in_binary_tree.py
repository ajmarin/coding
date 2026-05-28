class Solution:
    def __init__(self):
        self.perfect_tree_sizes = []

    def getSize(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left = self.getSize(root.left)
        right = self.getSize(root.right)
        if left == right != -1:
            self.perfect_tree_sizes.append(size := 1 + left + right)
            return size
        return -1

    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        self.getSize(root)
        if k <= len(self.perfect_tree_sizes):
            self.perfect_tree_sizes.sort()
            return self.perfect_tree_sizes[-k]
        return -1
