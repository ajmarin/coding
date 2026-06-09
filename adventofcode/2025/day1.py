import sys


def method1(lines):
    ans, deg = 0, 50

    for line in lines:
        delta = int(line[1:])
        if line[0] == "L":
            delta = -delta
        deg = (deg + delta) % 100
        ans += deg == 0

    return ans


def method2(lines):
    ans, deg = 0, 50

    for line in lines:
        delta = 1 if line[0] == "R" else -1
        for _ in range(int(line[1:])):
            deg = (deg + delta) % 100
            ans += deg == 0

    return ans


if __name__ == "__main__":
    lines = sys.stdin.readlines()
    for fn in (method1, method2):
        print(f"Password is {fn(lines)}")
