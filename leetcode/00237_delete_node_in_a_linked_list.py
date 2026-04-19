class Solution:
    def deleteNode(self, node):
        nodes, values = [], []
        curr = node
        while curr.next:
            nodes.append(curr)
            curr = curr.next
            values.append(curr.val)
        for node, val in zip(nodes, values):
            node.val = val
        node.next = None
