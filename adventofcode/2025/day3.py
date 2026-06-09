import sys


def get_power(bank, pick):
    n = len(bank)
    left = power = 0
    for lim in range(n - pick + 1, n + 1):
        idx = max(range(left, lim), key=bank.__getitem__)
        power = 10 * power + int(bank[idx])
        left = idx + 1
    return power


def part_one(banks):
    return sum(get_power(b, 2) for b in banks)


def part_two(banks):
    return sum(get_power(b, 12) for b in banks)


if __name__ == "__main__":
    banks = [l.strip() for l in sys.stdin.readlines()]
    print(f"There are {len(banks)} battery banks")
    print(f"Part one: {part_one(banks)}")
    print(f"Part one: {part_two(banks)}")
