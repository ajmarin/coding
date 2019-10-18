# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def mergeLists(self, a: ListNode, b: ListNode) -> ListNode:
        head = ListNode(0)
        current = head
        while a and b:
            if a.val < b.val:
                current.next = a
                a = a.next
            else:
                current.next = b
                b = b.next
            current = current.next
        current.next = a if a else b
        return head.next

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        interval = 1
        n = len(lists)
        while interval < n:
            i = 0
            while i + interval < n:
                lists[i] = self.mergeLists(lists[i], lists[i + interval])
                i += interval << 1
            interval <<= 1
        return lists[0] if len(lists) else None