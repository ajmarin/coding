class Solution:
    def minimumOperations(self, root: TreeNode) -> int:
        nodes = [root]
        ans = 0
        while nodes:
            values = [n.val for n in nodes]
            order = sorted(range(len(nodes)), key=values.__getitem__)
            for i in order:
                while order[i] != i:
                    order[order[i]], order[i] = order[i], order[order[i]]
                    ans += 1
            nodes = [c for n in nodes for c in (n.left, n.right) if c]
        return ans
