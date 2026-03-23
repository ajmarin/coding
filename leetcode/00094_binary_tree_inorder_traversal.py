class Solution:
    def inorderTraversal(self, root: Optional[TreeNode], ans=None) -> List[int]:
        ans = [] if ans is None else ans
        if not root:
            return ans
        self.inorderTraversal(root.left, ans)
        ans.append(root.val)
        self.inorderTraversal(root.right, ans)
        return ans
