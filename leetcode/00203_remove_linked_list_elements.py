class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        while head and head.val == val:
            head = head.next
        if not head:
            return None
        curr, prev = head.next, head
        while curr:
            if curr.val == val:
                prev.next = curr = curr.next
            else:
                prev, curr = curr, curr.next
        return head
