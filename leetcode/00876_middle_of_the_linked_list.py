class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        count, node = 0, head
        while node:
            count += 1
            node = node.next
        count >>= 1
        goal, node = 0, head
        while goal < count:
            goal += 1
            node = node.next
        return node