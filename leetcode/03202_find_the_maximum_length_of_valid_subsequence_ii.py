class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        indices = defaultdict(list)
        for i, n in enumerate(nums):
            indices[n % k].append(i)
        best = max(map(len, indices.values()))
        items = sorted(indices.items(), key=lambda x: -len(x[1]))
        for i, (x, xidx) in enumerate(items):
            for y, yidx in items[i + 1:]:
                if len(xidx) + len(yidx) <= best: continue
                iters = [iter(xidx), iter(yidx)]
                curr = min(xidx[0], yidx[0])
                pos = curr == yidx[0]
                size = 0
                while curr is not None:
                    size += 1
                    pos ^= 1
                    curr = next((x for x in iters[pos] if x > curr), None)
                best = size if size > best else best
        return best

