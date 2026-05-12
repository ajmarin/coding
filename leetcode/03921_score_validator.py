class Solution:
    def scoreValidator(self, events: list[str]) -> list[int]:
        counter = score = 0
        for e in events:
            match e:
                case "W":
                    counter += 1
                    if counter == 10:
                        break
                case "WD":
                    score += 1
                case "NB":
                    score += 1
                case _:
                    score += int(e)
        return [score, counter]
