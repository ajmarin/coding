class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        distinct = [w for w, count in Counter(arr).items() if count == 1]
        return distinct[k - 1] if len(distinct) >= k else ""
