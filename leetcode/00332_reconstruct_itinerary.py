class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets.sort()
        where_to = collections.defaultdict(collections.deque)
        for i, (f, _) in enumerate(tickets):
            where_to[f].append(i)
        used = [False] * len(tickets)
        def dfs(at: str, path: List[str] = None) -> List[str]:
            path = [at] if path is None else path
            if len(path) == len(tickets) + 1:
                return path
            for ti in where_to[at]:
                if used[ti]:
                    continue
                t = tickets[ti]
                used[ti] = True
                path.append(t[1])
                if dfs(t[1], path):
                    return path
                path.pop()
                used[ti] = False
            return []
        return dfs("JFK")