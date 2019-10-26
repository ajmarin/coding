# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        s = 0
        curr = head
        while curr:
            s += curr.val
            curr = curr.next
            if s == 0:
                head = curr
        if head:
            head.next = self.removeZeroSumSublists(head.next)
        return head