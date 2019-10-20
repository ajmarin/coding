# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        less_than_head = ListNode(0)
        less_than = less_than_head
        rest_head = ListNode(0)
        rest = rest_head
        while head:
            if head.val < x:
                less_than.next = head
                less_than = head
            else:
                rest.next = head
                rest = head
            head = head.next
        less_than.next = rest_head.next
        rest.next = None
        return less_than_head.next