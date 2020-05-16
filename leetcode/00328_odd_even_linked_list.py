# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        heads = [ListNode(), ListNode()]
        even_head = heads[1]
        pos = 0
        curr = head
        while curr:
            heads[pos].next = curr
            heads[pos] = curr
            pos ^= 1
            curr = curr.next
        heads[0].next = even_head.next
        heads[1].next = None
        return head