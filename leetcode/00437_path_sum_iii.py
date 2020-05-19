# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: TreeNode, curr: int, target: int, c: Counter) -> int:
        if not root:
            return 0
        total = curr + root.val
        ways = c[total - target]
        c[total] += 1
        ways += self.solve(root.left, total, target, c)
        ways += self.solve(root.right, total, target, c)
        c[total] -= 1
        return ways

    def pathSum(self, root: TreeNode, sum: int) -> int:
        c = Counter([0])
        return self.solve(root, 0, sum, c)