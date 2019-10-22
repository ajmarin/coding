# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        queue = [] # (node, level, position)
        i, clevel, qpos, width = [0]*4
        if root:
            queue.append((root, 1, 0))
            qpos += 1
        while i < qpos:
            node, level, pos = queue[i]
            i += 1
            if level != clevel:
                clevel = level
                left, right = pos, pos
            right = max(right, pos)
            left = min(left, pos)
            width = max(width, right - left + 1)
            if node.left:
                queue.append((node.left, level + 1, pos << 1))
                qpos += 1
            if node.right:
                queue.append((node.right, level + 1, 1 + (pos << 1)))
                qpos += 1
        return width