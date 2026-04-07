class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        special = set("!@#$%^&*()-+")
        return (
            len(password) >= 8
            and any(c.islower() for c in password)
            and any(c.isupper() for c in password)
            and any(c.isdigit() for c in password)
            and any(c in special for c in password)
            and all(c != p for p, c in zip(password, password[1:]))
        )
