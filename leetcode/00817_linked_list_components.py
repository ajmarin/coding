# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        s = set(G)
        answer, size = 0, 0
        while head:
            if head.val not in s:
                answer += size > 0
                size = 0
            else:
                size += 1
            head = head.next
        return answer + (size > 0)