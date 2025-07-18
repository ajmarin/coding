class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) // 3
        mid_section = nums[n:2*n]

        heap = [-x for x in nums[:n]]
        total = -sum(heap)
        heapify(heap)
        pre = deque([total])
        for num in mid_section:
            if -num > heap[0]:
                total += num
                heappush(heap, -num)
                total += heappop(heap)
            pre.append(total)

        heap = nums[2*n:]
        total = sum(heap)
        heapify(heap)
        suf = deque([total])
        for num in mid_section[::-1]:
            if num > heap[0]:
                total += num
                heappush(heap, num)
                total -= heappop(heap)
            suf.appendleft(total)

        return min(first - second for first, second in zip(pre, suf))

