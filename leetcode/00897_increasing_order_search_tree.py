# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        nodes = []
        def inorder(node: TreeNode):
            if node.left:
                inorder(node.left)
            nodes.append(node)
            if node.right:
                inorder(node.right)
        inorder(root)
        for i, n in enumerate(nodes):
            n.left = None
            if i + 1 < len(nodes):
                n.right = nodes[i + 1]
        return nodes[0] if nodes else None