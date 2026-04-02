class Solution:
    def getTargetCopy(
        self, original: TreeNode, cloned: TreeNode, target: TreeNode
    ) -> TreeNode:
        if original is None:
            return None
        if original == target:
            return cloned
        return self.getTargetCopy(
            original.left, cloned.left, target
        ) or self.getTargetCopy(original.right, cloned.right, target)
