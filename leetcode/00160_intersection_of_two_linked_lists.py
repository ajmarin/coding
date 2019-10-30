# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        tmpA, tmpB = headA, headB
        while tmpA != tmpB:
            tmpA = tmpA.next if tmpA else headB
            tmpB = tmpB.next if tmpB else headA
        return tmpA
