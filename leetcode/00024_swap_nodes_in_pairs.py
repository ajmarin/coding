# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        a, b, c = None, head, head.next
        new_head = c if c else b
        while c is not None:
            if a:
                a.next = c
            b.next = c.next
            c.next = b
            a, b = b, b.next
            c = b.next if b else None
        return new_head