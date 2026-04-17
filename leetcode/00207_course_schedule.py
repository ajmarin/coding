class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        deps = defaultdict(list)
        degree = [0] * numCourses
        for blocked, depends_on in prerequisites:
            deps[depends_on].append(blocked)
            degree[blocked] += 1
        q = deque(i for i in range(numCourses) if not degree[i])
        while q:
            for u in deps[q.popleft()]:
                degree[u] -= 1
                if not degree[u]:
                    q.append(u)
        return sum(degree) == 0
