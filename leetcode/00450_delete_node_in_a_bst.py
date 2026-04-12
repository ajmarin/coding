class Solution:
    def predecessor(self, root: TreeNode):
        root = root.left
        while root.right:
            root = root.right
        return root.val

    def successor(self, root: TreeNode):
        root = root.right
        while root.left:
            root = root.left
        return root.val

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif root.left == root.right:
            return None
        elif root.right:
            root.val = self.successor(root)
            root.right = self.deleteNode(root.right, root.val)
        else:
            root.val = self.predecessor(root)
            root.left = self.deleteNode(root.left, root.val)
        return root
