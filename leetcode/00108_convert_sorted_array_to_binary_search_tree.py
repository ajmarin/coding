class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        mid = len(nums) // 2
        return TreeNode(
            nums[mid],
            self.sortedArrayToBST(nums[:mid]),
            self.sortedArrayToBST(nums[mid + 1 :]),
        )
