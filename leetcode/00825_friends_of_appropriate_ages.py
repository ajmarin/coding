class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        # Counting sort
        counts = [0] * 121
        for age in ages: counts[age] += 1
        index = 0
        for i, c in enumerate(counts):
            n = c
            while n:
                n -= 1
                ages[index + n] = i
            index += c
        # Compute friend requests
        ans = cut_index = total = 0
        for age, cnt in enumerate(counts):
            if not cnt: continue
            if age > 14:
                cut_index = bisect_right(ages, 0.5 * age + 7, cut_index)
                ans += cnt * (total - cut_index + cnt - 1)
            total += cnt
        return ans

