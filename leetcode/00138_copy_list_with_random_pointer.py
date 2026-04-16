class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        mapping, node = {}, head
        while node:
            mapping[node] = Node(node.val, node.next)
            node = node.next
        for old, new in mapping.items():
            new.next = mapping.get(old.next)
            new.random = mapping.get(old.random)
        return mapping.get(head)
