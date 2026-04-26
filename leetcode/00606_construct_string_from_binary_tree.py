class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if not root:
            return ""
        left = right = ""
        if root.left:
            left = f"({self.tree2str(root.left)})"
        if root.right:
            left = left or "()"
            right = f"({self.tree2str(root.right)})"
        return f"{root.val}{left}{right}"
