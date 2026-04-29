class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes, parents = {}, {}

        def get_node(val: int) -> TreeNode:
            if val not in nodes:
                nodes[val] = TreeNode(val)
                parents[val] = -1
            return nodes[val]

        for p, v, is_left in descriptions:
            parent, child = get_node(p), get_node(v)
            parents[v] = p
            if is_left:
                parent.left = child
            else:
                parent.right = child
        return nodes[next(v for v, p in parents.items() if p == -1)]
