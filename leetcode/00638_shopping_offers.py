class Solution:
    def shoppingOffers(
        self, price: List[int], special: List[List[int]], needs: List[int]
    ) -> int:
        @cache
        def dfs(rem: Tuple[int]):
            best = sum(map(mul, rem, price))
            for s in special:
                p = s[-1]
                next_state = tuple(map(sub, rem, s[:-1]))
                if min(next_state) < 0:
                    continue
                best = best if best < p + dfs(next_state) else p + dfs(next_state)
            return best

        return dfs(tuple(needs))
