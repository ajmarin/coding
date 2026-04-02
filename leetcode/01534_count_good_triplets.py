class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        good = 0
        for i in range(n):
            ni = arr[i]
            for j in range(i + 1, n):
                nj = arr[j]
                if abs(nj - ni) > a:
                    continue
                for k in range(j + 1, n):
                    nk = arr[k]
                    good += abs(nk - nj) <= b and abs(nk - ni) <= c
        return good
