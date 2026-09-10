class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(node: TreeNode) -> Tuple[int, int]:
            if not node:
                return 0, 0, 0
            eql, tl, nl = dfs(node.left)
            eqr, tr, nr = dfs(node.right)
            total = tl + tr + node.val
            nodes = nl + nr + 1
            return eql + eqr + (total // nodes == node.val), total, nodes

        return dfs(root)[0]
