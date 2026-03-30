class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        index = bisect_right(letters, target)
        return letters[0] if index == len(letters) else letters[index]
