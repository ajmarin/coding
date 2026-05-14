class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        c = Counter(nums)

        @cache
        def get_chain_size(n: int) -> int:
            return 2 + get_chain_size(n * n) if c[n] > 1 and c[n * n] else 1

        ans = max(1, c[1] - (c[1] % 2 == 0))
        c[1] = 0
        for n in c.keys():
            ans = max(ans, get_chain_size(n))
        return ans
