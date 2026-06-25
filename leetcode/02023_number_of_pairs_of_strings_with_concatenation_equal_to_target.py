class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        pref_by_len = defaultdict(set)
        suff_by_len = defaultdict(set)
        for i, n in enumerate(nums):
            if target.startswith(n):
                pref_by_len[len(n)].add(i)
            if target.endswith(n):
                suff_by_len[len(n)].add(i)
        ans = 0
        for plen, pref_idx in pref_by_len.items():
            suff_idx = suff_by_len[len(target) - plen]
            ans += len(pref_idx) * len(suff_idx) - len(pref_idx & suff_idx)
        return ans
