# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int], index: int = 0) -> List[int]:
        if not root:
            return []
        s = collections.deque([(root, None)])
        def stack_children(node):
            if node.right:
                s.append((node.right, node))
            if node.left:
                s.append((node.left, node))
        flips = []
        while s:
            node, parent = s.pop()
            if node.val == voyage[index]:
                index += 1
                stack_children(node)
            elif not s:
                return [-1]
            else:
                other, oparent = s.pop()
                s.append((node, parent))
                if other.val != voyage[index]:
                    return [-1]
                flips.append(oparent.val)
                if other.val == voyage[index]:
                    index += 1
                    stack_children(other)
        return flips