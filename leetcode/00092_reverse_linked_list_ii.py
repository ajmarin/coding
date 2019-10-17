# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        current = head
        previous = None
        count = 1
        while count < m:
            previous = current
            current = current.next
            count += 1
        inversion_head = current
        inversion_previous = previous
        while count <= n:
            old_next = current.next
            current.next = previous
            previous = current
            current = old_next
            count += 1
        inversion_head.next = current
        if inversion_previous is not None:
            inversion_previous.next = previous
        return head if m > 1 else previous