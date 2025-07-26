class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        left_limits = defaultdict(list)
        for left, right in conflictingPairs:
            if left > right: left, right = right, left
            left_limits[right].append(left)

        ans = max_gain = 0
        limits = [0, 0]
        gain = [0] * (n + 1)
        for i in range(1, n + 1):
            for lim in left_limits[i]:
                if lim > limits[0]: limits = [lim, limits[0]]
                elif lim > limits[1]: limits[1] = lim
            ans += i - limits[0]
            gain[limits[0]] += limits[0] - limits[1]
            g = gain[limits[0]]
            max_gain = g if g > max_gain else max_gain
        return ans + max_gain

