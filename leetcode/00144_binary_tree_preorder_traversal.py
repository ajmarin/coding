class Solution:
    def preorderTraversal(self, root: Optional[TreeNode], ans=None) -> List[int]:
        if root is None:
            return []
        ans = [] if ans is None else ans
        ans.append(root.val)
        self.preorderTraversal(root.left, ans)
        self.preorderTraversal(root.right, ans)
        return ans
