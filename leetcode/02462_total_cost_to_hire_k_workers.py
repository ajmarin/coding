class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        remaining = deque(costs[candidates:-candidates])
        ans = 0
        if remaining:
            first, last = costs[:candidates], costs[-candidates:]
            heapify(first)
            heapify(last)
            while k and remaining:
                if first[0] <= last[0]:
                    ans += heapreplace(first, remaining.popleft())
                else:
                    ans += heapreplace(last, remaining.pop())
                k -= 1
            remaining = first + last
        if not k:
            return ans
        remaining = remaining or costs
        heapify(remaining)
        while k:
            ans += heappop(remaining)
            k -= 1
        return ans
