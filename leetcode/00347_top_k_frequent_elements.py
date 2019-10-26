class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        buckets = [[] for _ in nums]
        for n, f in collections.Counter(nums).items():
            buckets[-f].append(n)
        q = collections.deque()
        for b in filter(None, buckets):
            q.extend(b[:k-len(q)])
            if len(q) == k:
                break
        return q