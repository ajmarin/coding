# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:
    def __init__(self, root: TreeNode):
        self.root = root
        self.incomplete = collections.deque()
        q = collections.deque([root])
        while q:
            node = q.popleft()
            if not node.left or not node.right:
                self.incomplete.append(node)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

    def insert(self, v: int) -> int:
        parent = self.incomplete[0]
        self.incomplete.append(TreeNode(v))
        if not parent.left:
            parent.left = self.incomplete[-1]
        else:
            parent.right = self.incomplete[-1]
            self.incomplete.popleft()
        return parent.val

    def get_root(self) -> TreeNode:
        return self.root