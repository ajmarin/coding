class Solution:
    def insertGreatestCommonDivisors(
        self, head: Optional[ListNode]
    ) -> Optional[ListNode]:
        if not head:
            return None
        prev, node = head, head.next
        while node:
            prev.next = ListNode(gcd(prev.val, node.val), node)
            prev, node = node, node.next
        return head
