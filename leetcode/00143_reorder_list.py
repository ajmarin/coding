class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        s = []
        curr = head
        while curr:
            s.append(curr)
            curr = curr.next
        while s:
            tail = s.pop()
            if head == tail or head.next == tail:
                tail.next = None
                break
            tmp = head.next
            head.next = tail
            tail.next = tmp
            head = tmp
