"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node'], clones: Optional[dict] = None) -> Optional['Node']:
        if not node: return None
        clones = clones or dict()
        if node.val in clones: return clones[node.val]
        copy = Node(node.val)
        clones[node.val] = copy
        neighbors = copy.neighbors
        for neighbor in node.neighbors:
            neighbors.append(self.cloneGraph(neighbor, clones))
        return copy

