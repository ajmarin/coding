class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        by_content = defaultdict(list)
        for path in paths:
            directory, *files = path.split(" ")
            for f in files:
                fn, content = f[:-1].split("(")
                by_content[content].append(f"{directory}/{fn}")
        return [dups for dups in by_content.values() if len(dups) > 1]
