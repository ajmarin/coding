class Solution:
    def __init__(self, head: Optional[ListNode]):
        values = []
        while head:
            values.append(head.val)
            head = head.next
        self.values = values

    def getRandom(self) -> int:
        return random.choice(self.values)
