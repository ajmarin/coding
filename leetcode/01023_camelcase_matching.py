class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def matchesCondition(query: str):
            index = 0
            for c in query:
                if index < len(pattern) and c == pattern[index]:
                    index += 1
                elif 'A' <= c <= 'Z':
                    return False
            return index == len(pattern)
        return list(map(matchesCondition, queries))