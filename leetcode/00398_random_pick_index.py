class Solution:
    def __init__(self, nums: List[int]):
        self.num_to_indices = defaultdict(list)
        for i, n in enumerate(nums):
            self.num_to_indices[n].append(i)

    def pick(self, target: int) -> int:
        return random.choice(self.num_to_indices[target])
