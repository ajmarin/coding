class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        count = 0
        for node in preorder.split(','):
            if count == -1:
                return False
            count += (node != '#') - (node == '#')
        return count == -1