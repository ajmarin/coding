"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
import functools
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        answer = collections.deque()
        stack = collections.deque([root])
        while stack:
            top = stack.pop()
            answer.append(top.val)
            stack.extend(top.children[::-1])
        return answer