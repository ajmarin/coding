class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        ans = set()
        cnt = Counter(digits)

        def bt(pos, n):
            if pos == 3:
                if n % 2 == 0:
                    ans.add(n)
                return
            for d in range(pos == 0, 10):
                if cnt[d]:
                    cnt[d] -= 1
                    bt(pos + 1, 10 * n + d)
                    cnt[d] += 1

        bt(0, 0)
        return sorted(ans)
