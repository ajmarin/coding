# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(
        self, nums: List[int], head: Optional[ListNode]
    ) -> Optional[ListNode]:
        remove = set(nums)
        while head and head.val in remove:
            head = head.next
        prev, curr = None, head
        while curr:
            prev, curr = curr, curr.next
            while curr and curr.val in remove:
                curr = curr.next
            prev.next = curr
        return head
