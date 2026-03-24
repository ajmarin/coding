class Solution:
    def postorderTraversal(self, root: Optional[TreeNode], ans=None) -> List[int]:
        if root is None:
            return []
        ans = [] if ans is None else ans
        self.postorderTraversal(root.left, ans)
        self.postorderTraversal(root.right, ans)
        ans.append(root.val)
        return ans
