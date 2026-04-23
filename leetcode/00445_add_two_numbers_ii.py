class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if not l1:
            return l2
        if not l2:
            return l1
        nodes1 = []
        nodes2 = []
        while l1:
            nodes1.append(l1)
            l1 = l1.next
        while l2:
            nodes2.append(l2)
            l2 = l2.next
        carry = 0
        if len(nodes2) > len(nodes1):
            nodes1, nodes2 = nodes2, nodes1
        for n1, n2 in zip_longest(reversed(nodes1), reversed(nodes2)):
            v1, v2 = n1.val, n2.val if n2 else 0
            add = v1 + v2 + carry
            n1.val = add % 10
            carry = add // 10
        return ListNode(carry, nodes1[0]) if carry else nodes1[0]
