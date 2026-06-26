class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        N = 2 * len(nums) + 1
        tree = [0] * N

        def query(x: int) -> int:
            res = 0
            while x:
                res += tree[x]
                x -= x & -x
            return res

        def update(x: int) -> int:
            while x < N:
                tree[x] += 1
                x += x & -x

        bal = len(nums) + 1
        update(bal)
        ans = 0
        for x in nums:
            bal += 1 if x == target else -1
            update(bal)
            ans += query(bal - 1)
        return ans
