class Solution:
    def checkValidString(self, s: str) -> bool:
        def is_balanced(it, add: str) -> bool:
            balance = 0
            for i in it:
                balance += 1 if s[i] in add else -1
                if balance < 0:
                    return False
            return True
        n = len(s)    
        return is_balanced(range(n), '(*') and is_balanced(range(n - 1, -1, -1), '*)')