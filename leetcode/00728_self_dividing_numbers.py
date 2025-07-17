def is_self_dividing(n: int):
    x = n
    while x:
        d = x % 10
        if not d or n % d: return False
        x //= 10
    return True

