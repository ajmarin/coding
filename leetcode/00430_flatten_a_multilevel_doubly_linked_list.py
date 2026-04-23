class Solution:
    def flatten(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return None
        prev, q = None, [head]
        while q:
            curr = q.pop()
            if prev:
                curr.prev = prev
                prev.next = curr
            prev = curr
            if curr.next:
                q.append(curr.next)
            if curr.child:
                q.append(curr.child)
                curr.child = None
        return head
