class Solution:
    def leaves(self, node: TreeNode, leaves: List[int]) -> List[int]:
        if node is None:
            return
        if node.left is None and node.right is None:
            leaves.append(node.val)
        self.leaves(node.left, leaves)
        self.leaves(node.right, leaves)
        
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        l1, l2 = [], []
        self.leaves(root1, l1)
        self.leaves(root2, l2)
        return l1 == l2