# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        first = head
        current = head
        while current:
            while current and current.val == first.val:
                current = current.next
            first.next = current
            first = current
        return head