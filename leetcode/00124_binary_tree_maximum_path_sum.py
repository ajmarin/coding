class Solution:
    def solve(self, node: TreeNode) -> (float, int):
        '''Returns a tuple containing best sum from subtree and best path up to node'''
        if node is None:
            return (float("-inf"), 0)
        best_left, path_left = self.solve(node.left)
        best_right, path_right = self.solve(node.right)
        current = node.val + path_left + path_right
        return max(current, best_left, best_right), max(0, node.val + max(path_left, path_right))
    def maxPathSum(self, root: TreeNode) -> int:
        return self.solve(root)[0]