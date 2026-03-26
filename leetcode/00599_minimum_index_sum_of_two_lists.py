class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        if len(list1) > len(list2):
            list1, list2 = list2, list1
        idx = dict((word, index) for index, word in enumerate(list2))
        ans = []
        min_sum = 2000
        for i, word in enumerate(list1):
            index_sum = i + idx.get(word, min_sum)
            if index_sum < min_sum:
                min_sum = index_sum
                ans = [word]
            elif index_sum == min_sum:
                ans.append(word)
        return ans
