class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prev, head = head, head.next if head else None
        min_dist, max_dist = 10**6, 0
        curr, last_crit = 1, 0
        while head and head.next:
            nxt = head.next
            if prev.val > head.val < nxt.val or prev.val < head.val > nxt.val:
                if last_crit:
                    min_dist = (
                        min_dist if min_dist < curr - last_crit else curr - last_crit
                    )
                    max_dist += curr - last_crit
                last_crit = curr
            curr += 1
            prev, head = head, nxt
        return [-(min_dist == 10**6) | min_dist, -(max_dist == 0) | max_dist]
