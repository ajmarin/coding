# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder(node: TreeNode, parent: TreeNode):
            rval = node
            if node.left:
                rval = inorder(node.left, node)
                node.left = None
            if node.right:
                node.right = inorder(node.right, parent)
            else:
                node.right = parent
            return rval
        return inorder(root, None)