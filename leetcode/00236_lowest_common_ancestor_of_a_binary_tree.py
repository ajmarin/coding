# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        depth, parent = {}, {}
        def dfs(root: TreeNode, d: int):
            if not root:
                return
            depth[root] = d
            if root.left:
                parent[root.left] = root
                dfs(root.left, d + 1)
            if root.right:
                parent[root.right] = root
                dfs(root.right, d + 1)
        dfs(root, 0)
        if depth[q] > depth[p]:
            p, q = q, p
        while depth[p] > depth[q]:
            p = parent[p]
        while p != q:
            p = parent[p]
            q = parent[q]
        return p