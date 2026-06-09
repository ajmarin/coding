import sys


def duplicated(starts, ends):
    n = len(ranges)
    ans = pos = 0
    for i in range(1, 10**5):
        num = int(str(i) * 2)
        while pos < n:
            if num <= ends[pos]:
                break
            pos += 1
        else:
            break
        if num >= starts[pos]:
            ans += num
    return ans


def repeated(starts, ends):
    n = len(starts)
    ans = pos = 0

    limit = ends[-1]
    checked = set()

    for i in range(1, 10**5):
        stri = curr = str(i)
        curr += stri
        cnum = int(curr)
        pos = 0
        while cnum <= limit:
            if cnum not in checked:
                checked.add(cnum)
                while ends[pos] < cnum:
                    pos += 1
                if cnum >= starts[pos]:
                    ans += cnum
            curr += stri
            cnum = int(curr)
    return ans


if __name__ == "__main__":
    lines = sys.stdin.readlines()
    ranges = [[int(i) for i in line.split("-")] for line in lines[0].split(",")]
    ranges.sort()
    starts = [r[0] for r in ranges]
    ends = [r[1] for r in ranges]
    print(f"Sum of duplicated numbers is: {duplicated(starts, ends)}")
    print(f"Sum of repeated numbers is: {repeated(starts, ends)}")
