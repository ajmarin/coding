class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        half = (len(arr) + 1) >> 1
        ans = curr = 0
        for _, cnt in Counter(arr).most_common():
            ans += 1
            if (curr := curr + cnt) >= half:
                break
        return ans
