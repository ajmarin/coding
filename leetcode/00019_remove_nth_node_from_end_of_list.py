# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        before = head
        after = head
        for i in range(n):
            after = after.next
        if after is None and before == head:
            return head.next
        while after.next is not None:
            before = before.next
            after = after.next
        before.next = before.next.next
        return head