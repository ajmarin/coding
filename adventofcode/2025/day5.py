import bisect
import sys


def part_one(starts, ends, queries):
    ans = 0
    n = len(starts)
    print(f"There are {len(queries)} queries")
    for q in queries:
        for s, e in zip(starts, ends):
            if s > q:
                break
            if s <= q <= e:
                ans += 1
                break
    return ans


def part_two(starts, ends):
    curr_start, curr_end = 0, -1
    ans = 0
    for s, e in zip(starts + [ends[-1] + 1], ends + [-1]):
        if s > curr_end:
            ans += curr_end - curr_start + 1
            curr_start, curr_end = s, e
        else:
            curr_end = e if e > curr_end else curr_end
    return ans


if __name__ == "__main__":
    lines = iter(sys.stdin.readlines())
    ranges = []
    for line in lines:
        line = line.strip()
        if not line:
            break
        ranges.append([int(p) for p in line.split("-")])

    queries = []
    for line in lines:
        queries.append(int(line))

    ranges.sort()
    starts = [r[0] for r in ranges]
    ends = [r[1] for r in ranges]
    print(f"Part one: {part_one(starts, ends, queries)}")
    print(f"Part two: {part_two(starts, ends)}")
