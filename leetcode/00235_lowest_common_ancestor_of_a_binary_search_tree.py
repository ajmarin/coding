class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode:
        if not root:
            return None
        rv, pv, qv = root.val, p.val, q.val
        if rv < pv and rv < qv:
            return self.lowestCommonAncestor(root.right, p, q)
        if rv > pv and rv > qv:
            return self.lowestCommonAncestor(root.left, p, q)
        return root
