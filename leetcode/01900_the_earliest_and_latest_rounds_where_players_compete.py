class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        firstPlayer, secondPlayer = firstPlayer - 1, secondPlayer - 1
        winner = [i == firstPlayer or i == secondPlayer for i in range(n)]

        ans = set()

        @cache
        def bt(mask: int, first: int, second: int, depth = 0):
            depth += 1
            ones = [i for i in range(mask.bit_length()) if mask & (1 << i)]

            elim = []
            for i in range(len(ones) // 2):
                left, right = ones[i], ones[~i]
                if left == first and right == second:
                    ans.add(depth)
                    return
                if winner[left]: elim.append([right])
                elif winner[right]: elim.append([left])
                else: elim.append([left, right])

            for to_remove in product(*elim):
                new_mask = mask
                for n in to_remove: new_mask ^= 1 << n
                bt(new_mask, first, second, depth)

        bt(2**n - 1, firstPlayer, secondPlayer)
        return [min(ans), max(ans)]

