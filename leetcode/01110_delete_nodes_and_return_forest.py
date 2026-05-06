class Solution:
    def cleanup(
        self, node: Optional[TreeNode], to_delete: Set[int], forest: List[TreeNode]
    ) -> TreeNode:
        if not node:
            return None
        node.left = self.cleanup(node.left, to_delete, forest)
        node.right = self.cleanup(node.right, to_delete, forest)
        if node.val in to_delete:
            forest.extend(c for c in (node.left, node.right) if c)
            return None
        return node

    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        forest = []
        root = self.cleanup(root, set(to_delete), forest)
        return ([root] + forest) if root else forest
