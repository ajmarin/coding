class Solution:
    def splitListToParts(
        self, head: Optional[ListNode], k: int
    ) -> List[Optional[ListNode]]:
        count, curr = 0, head
        while curr:
            count += 1
            curr = curr.next

        ans = []
        prev, curr = None, head
        per_part, rem = count // k, count % k
        count = 0
        while curr:
            prev, curr = curr, curr.next
            if (count := count + 1) == per_part + (rem > 0):
                if prev:
                    prev.next = None
                ans.append(head)
                head = curr
                rem -= 1
                count = 0
        while len(ans) != k:
            ans.append(None)
        return ans
