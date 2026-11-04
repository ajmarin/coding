class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        INF = 10**15
        n = len(nums)
        low, high = SortedList(nums[: x - 1]), SortedList()
        sum_high, sum_low = 0, sum(low)

        def insert_and_rebalance(n: int):
            nonlocal sum_low, sum_high
            if low and n <= low[-1]:
                low.add(n)
                sum_low += n
            else:
                high.add(n)
                sum_high += n
            for _ in range(1, len(low) - len(high)):
                switch = low[-1]
                low.remove(switch)
                sum_low -= switch
                high.add(switch)
                sum_high += switch
            while len(high) > len(low):
                switch = high[0]
                low.add(switch)
                sum_low += switch
                high.remove(switch)
                sum_high -= switch

        left = -1
        costs = [INF] * (x - 1)
        for i in range(x - 1, n):
            insert_and_rebalance(nums[i])
            median = low[-1]
            cost = sum_high - sum_low + median * (len(low) - len(high))
            costs.append(cost)
            rem = nums[left := left + 1]
            if rem <= median:
                low.remove(rem)
                sum_low -= rem
            else:
                high.remove(rem)
                sum_high -= rem

        prev = [0] * (n + 1)
        for _ in range(k):
            curr = [INF]
            for i in range(n):
                curr.append(
                    min(curr[-1], prev[i - x + 1] + costs[i]) if i >= x - 1 else INF
                )
            prev = curr
        return curr[-1]
