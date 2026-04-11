class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        prev = None
        mid = fast = head
        while fast and fast.next:
            prev, mid = mid, mid.next
            fast = fast.next.next
        prev.next = mid.next
        return head
