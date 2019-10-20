# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k == 1:
            return head
        pfirst = ListNode(0)
        pfirst.next = head
        ret = pfirst
        while head:
            tmp_head = head
            count = 0
            for i in range(k):
                if head:
                    count += 1
                    head = head.next
            if count == k:
                prev, curr = tmp_head, tmp_head.next
                for count in range(k - 1):
                    tmp = curr.next
                    curr.next = prev
                    prev = curr
                    curr = tmp
                pfirst.next = prev
                tmp_head.next = curr
                pfirst = tmp_head
                head = curr
        return ret.next