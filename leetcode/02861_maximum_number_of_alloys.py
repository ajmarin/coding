class Solution:
    def maxNumberOfAlloys(
        self,
        n: int,
        k: int,
        budget: int,
        composition: List[List[int]],
        stock: List[int],
        cost: List[int],
    ) -> int:
        def create_alloys(q: int) -> bool:
            for comp in composition:
                q_cost = sum(
                    max(need * q - have, 0) * c
                    for need, have, c in zip(comp, stock, cost)
                )
                if q_cost <= budget:
                    return True
            return False

        low, high = 0, max(stock) + budget // min(cost) + 1
        while low < high:
            mid = (low + high) >> 1
            if create_alloys(mid):
                low = mid + 1
            else:
                high = mid
        return low - 1
