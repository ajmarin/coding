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
        i = position
        while i < len(candidates):
            if candidates[i] <= target:
                used.append(candidates[i])
                self.find_combinations(candidates, target - candidates[i], i + 1, used, solutions)
                while i < len(candidates) - 1 and candidates[i] == candidates[i + 1]:
                    i += 1
                used.pop()
            else:
                break
            i += 1
                
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        solutions = []
        candidates.sort()
        self.find_combinations(candidates, target, 0, [], solutions)
        return solutions