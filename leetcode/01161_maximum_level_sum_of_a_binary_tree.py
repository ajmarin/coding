# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        max_sum = -10**10
        queue = [None] * 10**4
        qpos = 1
        queue[0] = (root, 1)
        i, rsum = 0, 0
        answer, clevel = -1, -1
        while i < qpos:
            node, level = queue[i]
            if level != clevel:
                if rsum > max_sum:
                    answer = clevel
                    max_sum = rsum
                clevel = level
                rsum = 0
            rsum += node.val
            i += 1
            if node.left:
                queue[qpos] = (node.left, level + 1)
                qpos += 1
            if node.right:
                queue[qpos] = (node.right, level + 1)
                qpos += 1
        return clevel if rsum > max_sum else answer