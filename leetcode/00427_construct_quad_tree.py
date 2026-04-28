"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def construct(self, grid: List[List[int]], size=-1, top=0, left=0) -> "Node":
        size = size if size != -1 else len(grid)
        total = sum(
            grid[i][j] for i in range(top, top + size) for j in range(left, left + size)
        )
        if total == 0 or total == size * size:
            return Node(total > 0, True)
        size >>= 1
        return Node(
            0,
            False,
            self.construct(grid, size, top, left),
            self.construct(grid, size, top, left + size),
            self.construct(grid, size, top + size, left),
            self.construct(grid, size, top + size, left + size),
        )
