class Solution:
    def bt(
        self,
        digits: int,
        target: int,
        min_digit: int,
        used: List[int],
        ans: List[List[int]],
    ):
        if digits == 1:
            if min_digit <= target < 10:
                ans.append(used + [target])
            return
        for d in range(min_digit, 1 + min(target, 9)):
            used.append(d)
            self.bt(digits - 1, target - d, d + 1, used, ans)
            used.pop()

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        self.bt(k, n, 1, [], ans)
        return ans
