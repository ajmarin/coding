# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        q = collections.deque([root])
        pos = 0
        while pos < len(q):
            node = q[pos]
            if node is None:
                q[pos] = ''
            else:
                q[pos] = str(node.val)
                q.append(node.left)
                q.append(node.right)
            pos += 1
        return ','.join(list(q))

    def deserialize(self, data):
        nodes = list(map(lambda x: TreeNode(int(x)) if x else None, data.split(',')))
        q = collections.deque([nodes[0]] if nodes[0] else [])
        index = 1
        while q:
            node = q.popleft()
            left = nodes[index]
            right = nodes[index + 1]
            if left:
                node.left = left
                q.append(left)
            if right:
                node.right = right
                q.append(right)
            index += 2
        return nodes[0]