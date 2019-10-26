# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def inorder(root: TreeNode) -> List[int]:
            if not root:
                return []
            return inorder(root.left) + [root.val] + inorder(root.right)
        nums = inorder(root)
        left, right = 0, len(nums) - 1
        while left < right:
            add = nums[left] + nums[right]
            if add == k:
                return True
            if add < k:
                left += 1
            else:
                right -= 1
        return False