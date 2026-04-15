class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        friend_set = set(friends)
        return [o for o in order if o in friend_set]
