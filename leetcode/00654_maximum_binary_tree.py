class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        idx = max(range(len(nums)), key=lambda i: nums[i])
        return TreeNode(
            nums[idx],
            self.constructMaximumBinaryTree(nums[:idx]),
            self.constructMaximumBinaryTree(nums[idx + 1 :]),
        )
