# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        head = ListNode(0)
        curr = head
        while curr is not None:
            carry = carry + (0 if l1 is None else l1.val) + (0 if l2 is None else l2.val)
            curr.val = carry % 10
            carry = carry // 10
            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None
            if l1 or l2 or carry:
                curr.next = ListNode(carry)
            curr = curr.next
        return head