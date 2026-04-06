class Solution:
    RULE_KEY_TO_INDEX = {
        "type": 0,
        "color": 1,
        "name": 2,
    }

    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        index = self.RULE_KEY_TO_INDEX[ruleKey]
        return sum(item[index] == ruleValue for item in items)
