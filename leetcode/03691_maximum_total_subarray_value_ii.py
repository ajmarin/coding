class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        top = [0] * (n << 2)
        bot = [0] * (n << 2)

        def build(pos: int, l: int, r: int) -> (int, int):
            if l == r:
                top[pos] = bot[pos] = nums[l]
                return nums[l], nums[l]
            m = (l + r) >> 1
            left_bot, left_top = build(2 * pos, l, m)
            right_bot, right_top = build(2 * pos + 1, m + 1, r)
            bot[pos] = left_bot if left_bot < right_bot else right_bot
            top[pos] = left_top if left_top > right_top else right_top
            return bot[pos], top[pos]

        def get_query_fn(arr: List[int], default: int, cmp):
            def query_fn(ql: int, qr: int, pos=1, l=0, r=n - 1) -> int:
                if ql > r or qr < l:
                    return default
                if ql <= l and r <= qr:
                    return arr[pos]
                m = (l + r) >> 1
                return cmp(
                    query_fn(ql, qr, pos * 2, l, m),
                    query_fn(ql, qr, pos * 2 + 1, m + 1, r),
                )

            return query_fn

        qmin = get_query_fn(bot, 10**18, min)
        qmax = get_query_fn(top, -(10**18), max)

        last = n - 1
        build(1, 0, last)
        h = [(qmin(l, last) - qmax(l, last), l, last) for l in range(n)]
        heapify(h)
        ans = 0
        for _ in range(k):
            val, l, r = heappop(h)
            ans -= val
            r -= 1
            if r >= l:
                heappush(h, (qmin(l, r) - qmax(l, r), l, r))
        return ans
