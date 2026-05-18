class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        values = []
        while head:
            values.append(head.val)
            head = head.next
        ans, s = [], []
        for n in values[::-1]:
            while s and n >= s[-1]:
                s.pop()
            ans.append(s[-1] if s else 0)
            if not s or n < s[-1]:
                s.append(n)
        return ans[::-1]
