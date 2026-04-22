def is_ipv4(s: str):
    if s.count(".") != 3:
        return False
    parts = s.split(".")
    for p in parts:
        if not len(p) or p[0] == "0" and len(p) > 1:
            return False
        if any(not c.isdigit() for c in p):
            return False
        if int(p) > 255:
            return False
    return True


def is_ipv6(s: str):
    return s.count(":") == 7 and all(
        1 <= len(p) <= 4 and all(c.isdigit() or "a" <= c.lower() <= "f" for c in p)
        for p in s.split(":")
    )


class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        if is_ipv4(queryIP):
            return "IPv4"
        return "IPv6" if is_ipv6(queryIP) else "Neither"
