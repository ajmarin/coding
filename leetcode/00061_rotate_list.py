# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None or k == 0:
            return head
        n = 1
        curr = head
        while curr.next is not None:
            curr = curr.next
            n += 1
        k = n - (k % n)
        curr.next = head
        while k:
            curr = curr.next
            k -= 1
        head = curr.next
        curr.next = None
        return head