class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        freqs = Counter()
        curr_sum = left = 0
        remaining = SortedList()
        top = SortedList()
        ans = []

        def update(num, delta):
            nonlocal curr_sum
            f = freqs[num]
            if f:
                old = (f, num)
                if old in top:
                    top.remove(old)
                    if delta > 0:
                        f += delta
                        top.add((f, num))
                        freqs[num] = f
                        curr_sum += num
                        return
                    curr_sum -= f * num
                else:
                    remaining.discard(old)
            f += delta
            freqs[num] = f
            if f:
                remaining.add((f, num))
            while len(top) < x and remaining:
                cnt, num = remaining.pop()
                top.add((cnt, num))
                curr_sum += cnt * num
            while remaining and remaining[-1] > top[0]:
                cnt_high, high = remaining.pop()
                cnt_low, low = top.pop(0)
                curr_sum += cnt_high * high - cnt_low * low
                remaining.add((cnt_low, low))
                top.add((cnt_high, high))

        for num in nums[:k]:
            update(num, 1)
        ans.append(curr_sum)
        for num in nums[k:]:
            update(num, 1)
            update(nums[left], -1)
            ans.append(curr_sum)
            left += 1
        return ans
