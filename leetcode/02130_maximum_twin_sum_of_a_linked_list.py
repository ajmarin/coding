class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        values = []
        while head:
            values.append(head.val)
            head = head.next
        return max(values[i] + values[~i] for i in range(len(values) >> 1))
