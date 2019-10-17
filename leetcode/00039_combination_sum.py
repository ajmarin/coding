class Solution:
    def find_combinations(
        self, 
        candidates: List[int], 
        target: int, 
        position: int,
        used: List[int], 
        solutions: List[List[int]],
    ):
        if target == 0:
            solutions.append([n for n in used])
            return
        for i in range(position, len(candidates)):
            if candidates[i] <= target:
                used.append(candidates[i])
                self.find_combinations(candidates, target - candidates[i], i, used, solutions)
                used.pop()
            else:
                break
                
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        solutions = []
        candidates.sort()
        self.find_combinations(candidates, target, 0, [], solutions)
        return solutions