# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        first, second, prev = [None] * 3
        last_print = None
        current = root
        while current:
            if current.left is None:
                if last_print and last_print.val > current.val:
                    first = first or last_print
                    second = current
                last_print = current
                current = current.right
            else:
                prev = current.left
                while prev.right and prev.right != current:
                    prev = prev.right
                if prev.right is None:
                    prev.right = current
                    current = current.left
                else:
                    prev.right = None
                    if last_print.val > current.val:
                        first = first or last_print
                        second = current
                    last_print = current
                    current = current.right
        first.val, second.val = second.val, first.val