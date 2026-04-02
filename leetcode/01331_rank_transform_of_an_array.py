class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        num_to_rank = {num: rank + 1 for rank, num in enumerate(sorted(set(arr)))}
        return [num_to_rank[n] for n in arr]
