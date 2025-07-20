class Node:
    def __init__(self):
        self.children = defaultdict(lambda: Node())
        self.serialized = ""

    def serialize(self):
        if self.serialized: return self.serialized
        l = []
        for folder, node in self.children.items():
            l.append(f"{folder}({node.serialize()})")
        l.sort()
        self.serialized = "".join(l)
        return self.serialized

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Node()

        for path in paths:
            at = root
            for folder in path:
                at = at.children[folder]

        root.serialize()

        cnt = Counter()
        q = deque([root])
        while q:
            at = q.popleft()
            if at.serialized:
                cnt[at.serialized] += 1
                q.extend(at.children.values())

        ans, path = [], []
        def dfs(node):
            if cnt[node.serialized] > 1: return
            if path: ans.append(path[:])

            for folder, node in node.children.items():
                path.append(folder)
                dfs(node)
                path.pop()

        dfs(root)
        return ans

