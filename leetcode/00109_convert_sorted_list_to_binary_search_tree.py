class Solution:
    def sortedNumsToBST(self, start: int, end: int) -> Optional[TreeNode]:
        if start > end:
            return None
        mid = (start + end) // 2
        left = self.sortedNumsToBST(start, mid - 1)
        right = self.sortedNumsToBST(mid + 1, end)
        return TreeNode(self.nums[mid], left, right)

    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        self.nums = nums
        return self.sortedNumsToBST(0, len(nums) - 1)
