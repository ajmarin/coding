class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        reqs = [0] * numCourses
        deps = [collections.deque() for _ in range(numCourses)]
        for a, b in prerequisites:
            reqs[a] += 1
            deps[b].append(a)
        solution = collections.deque(filter(lambda i: not reqs[i], range(numCourses)))
        taken = 0
        while taken < len(solution):
            curr = solution[taken]
            taken += 1
            for dep in deps[curr]:
                reqs[dep] -= 1
                if not reqs[dep]:
                    solution.append(dep)
        return list(solution) if taken == numCourses else []