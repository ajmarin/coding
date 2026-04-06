class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        prev = -1
        for word in s.split(" "):
            if word[0].isdigit():
                num = int(word)
                if num <= prev:
                    return False
                prev = num
        return True
