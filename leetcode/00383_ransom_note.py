class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_count = collections.Counter(magazine)
        return all(v <= mag_count[k] for k, v in collections.Counter(ransomNote).items())