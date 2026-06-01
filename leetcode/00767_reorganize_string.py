class Solution:
    def reorganizeString(self, s: str) -> str:
        cnt = Counter(s)
        if max(cnt.values()) > (len(s) + 1) >> 1:
            return ""

        h = [(count, k) for k, count in cnt.items()]
        heapify_max(h)

        ans = []
        prev_cnt, prev_x = 0, 0
        while h:
            cnt, x = heappop_max(h)
            ans.append(x)
            if prev_cnt:
                heappush_max(h, (prev_cnt, prev_x))
            prev_cnt, prev_x = cnt - 1, x
        return "".join(ans)
