class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        pq = []
        ans = decreased = 0
        for i, (a, b) in enumerate(pairwise(nums)):
            heappush(pq, (a + b, i))
            decreased += a > b

        before = list(range(-1, len(nums) - 1))
        after = list(range(1, len(nums) + 1))
        after[-1] = -1

        while decreased > 0:
            total, first = heappop(pq)
            second = after[first]
            if second == -1 or total != nums[first] + nums[second]:
                continue
            ans += 1
            decreased -= nums[first] > nums[second]

            if before[first] != -1:
                p = nums[before[first]]
                decreased += (p > total) - (p > nums[first])
                heappush(pq, (p + total, before[first]))

            if after[second] != -1:
                before[after[second]] = first
                n = nums[after[second]]
                decreased += (total > n) - (nums[second] > n)
                heappush(pq, (total + n, first))

            nums[first] = total

            after[first] = after[second]
            before[second] = after[second] = -1
        return ans
