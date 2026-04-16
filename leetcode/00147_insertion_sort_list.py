class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        nodes = []
        while head:
            nodes.append(head)
            head = head.next
        nodes.sort(key=lambda n: n.val)
        prev = nodes[0]
        for node in nodes[1:]:
            prev.next = node
            prev = node
        nodes[-1].next = None
        return nodes[0]
