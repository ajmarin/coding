class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ignoring = False
        answer = []
        pieces = ''
        def validate_block_comment(line, index):
            close = line.find('*/',index + 2)
            ignoring = close == -1
            ret = (line[:index] if index != -2 else '') + ('' if ignoring else line[close + 2:])
            return ret, ignoring
        for line in source:
            if ignoring:
                line, ignoring = validate_block_comment(line, -2)
                if ignoring:
                    continue
            comment = line.find('//')
            block_comment = line.find('/*')
            while comment != -1 or block_comment != -1:
                if comment != -1 and block_comment != -1:
                    if comment < block_comment:
                        line = line[:comment]
                    elif block_comment < comment:
                        line, ignoring = validate_block_comment(line, block_comment)
                        comment = line.find('//')
                elif block_comment != -1:
                    line, ignoring = validate_block_comment(line, block_comment)
                else:
                    line = line[:comment]
                comment = line.find('//')
                block_comment = line.find('/*')
            pieces = pieces + line
            if not ignoring and len(pieces):
                answer.append(pieces)
                pieces = ''
        return answer