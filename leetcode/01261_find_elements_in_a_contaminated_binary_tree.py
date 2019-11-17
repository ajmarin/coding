# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements:
    def __init__(self, root: TreeNode):
        self.root = root
        self.has = set()
        def dfs(n: TreeNode, v: int):
            if not n:
                return
            n.val = v
            self.has.add(v)
            if n.left:
                dfs(n.left, 2 * v + 1)
            if n.right:
                dfs(n.right, 2 * v + 2)
        dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.has