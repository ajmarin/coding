class Solution:
    def diameter(self, root: TreeNode) -> (int, int):
        if root is None:
            return (0, 0)
        left = self.diameter(root.left)
        right = self.diameter(root.right)
        droot = left[1] + right[1]
        depth = 1 + max(left[1], right[1])
        return (max(droot, left[0], right[0]), depth)
           

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        return self.diameter(root)[0]