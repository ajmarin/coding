class Solution:
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        def dfs(node: TreeNode, path_val = 0):
            if node is None: return -inf
            path_val += node.val
            if node.left is None and node.right is None:
                return path_val
            left = dfs(node.left, path_val)
            if left < limit: node.left = None
            right = dfs(node.right, path_val)
            if right < limit: node.right = None
            return left if left > right else right

        return root if dfs(root) >= limit else None

