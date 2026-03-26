class Solution:
    def binaryTreePaths(
        self, root: Optional[TreeNode], path=[], ans: Optional[List[str]] = None
    ) -> List[str]:
        if not root:
            return []
        ans = [] if ans is None else ans
        path.append(str(root.val))
        if root.left is None and root.right is None:
            ans.append("->".join(path))
        else:
            self.binaryTreePaths(root.left, path, ans)
            self.binaryTreePaths(root.right, path, ans)
        path.pop()
        return ans
