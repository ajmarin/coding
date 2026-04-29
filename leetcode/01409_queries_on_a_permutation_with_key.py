class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        arr = list(range(1, m + 1))
        ans = []
        for q in queries:
            i = next(i for i in range(m) if arr[i] == q)
            ans.append(i)
            arr[: i + 1] = [q] + arr[:i]
        return ans
