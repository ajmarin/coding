MOD = 10**9 + 7


def split(arr: List[int]) -> Tuple[int, List[int], List[int]]:
    root, *rest = arr
    left, right = [], []
    for x in rest:
        if x < root:
            left.append(x)
        else:
            right.append(x)
    return root, left, right


class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        def ways(arr: List[int]) -> int:
            n = len(arr)
            if n < 3:
                return 1
            root, left, right = split(arr)
            return ways(left) * ways(right) * comb(n - 1, len(left)) % MOD

        return (ways(nums) - 1) % MOD
