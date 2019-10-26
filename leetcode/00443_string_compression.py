class Solution:
    def compress(self, chars: List[str]) -> int:
        index = 0
        count = 1
        for i in range(len(chars)):
            if i == len(chars) - 1 or chars[i] != chars[i + 1]:
                chars[index] = chars[i]
                index += 1
                if count > 1:
                    for c in str(count):
                        chars[index] = c
                        index += 1
                count = 0
            count += 1
        return index