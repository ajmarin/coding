class Solution:
    def minJumps(self, arr: List[int]) -> int:
        indices = defaultdict(list)
        for i, x in enumerate(arr):
            indices[x].append(i)

        n = len(arr)
        cost = [-1] * n
        cost[0] = 0
        q = deque([0])

        def enqueue(x, c):
            if x < 0 or x >= n or cost[x] != -1:
                return
            cost[x] = c
            q.append(x)

        while cost[-1] == -1:
            at = q.popleft()
            c = cost[at] + 1
            enqueue(at - 1, c)
            enqueue(at + 1, c)
            neighbors = indices[arr[at]]
            while neighbors:
                enqueue(neighbors.pop(), c)
        return cost[-1]
