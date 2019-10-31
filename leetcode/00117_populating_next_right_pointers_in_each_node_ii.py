"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return
        q = collections.deque([(root, 0)])
        clevel = -1
        while q:
            node, level = q.popleft()
            if level != clevel:
                clevel = level
                node_right = None
            node.next = node_right
            node_right = node
            if node.right:
                q.append((node.right, level + 1))
            if node.left:
                q.append((node.left, level + 1))
        return root