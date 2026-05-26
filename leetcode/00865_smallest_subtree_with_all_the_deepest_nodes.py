class Solution:
    def __init__(self):
        self.depths = {None: 0}

    def dfs(self, node: Optional[TreeNode]):
        if not node:
            return 0
        if node.val not in self.depths:
            self.depths[node.val] = 1 + max(self.dfs(node.left), self.dfs(node.right))
        return self.depths[node.val]

    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        if left == right:
            return root
        return self.subtreeWithAllDeepest(root.left if left > right else root.right)
