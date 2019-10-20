# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy_head = ListNode(0)
        curr = dummy_head
        last = None
        count = 0
        while head:
            if not last or head.val != last.val:
                if count == 1:
                    curr.next = last
                    curr = last
                last = head
                count = 1
            else:
                count += 1
            head = head.next
        if count == 1:
            curr.next = last
            curr = last
        if curr:
            curr.next = None
        return dummy_head.next