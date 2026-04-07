class Solution:
    def minNumberOfHours(
        self,
        initialEnergy: int,
        initialExperience: int,
        energy: List[int],
        experience: List[int],
    ) -> int:
        bonus = highest = 0
        for xp in experience:
            required = 1 + xp - bonus
            highest = required if required > highest else highest
            bonus += xp
        return max(highest - initialExperience, 0) + max(
            sum(energy) + 1 - initialEnergy, 0
        )
