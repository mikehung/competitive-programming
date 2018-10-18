#!/usr/bin/env python

class Solution(object):
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        def do_line_comment(i, idx_line_commnet):
            source[i] = source[i][:idx_line_commnet]
            if not source[i]:
                del source[i]
            else:
                i += 1

        def do_block_comment(i, idx_beg_block_comment):
            in_beg_block_comment = True
            while True:
                idx_end_block_commnet = source[i].find(end_block_commnet)
                if idx_end_block_commnet == -1:
                    if in_beg_block_comment:
                        in_beg_block_comment = False
                        source[i] = source[i][:idx_beg_block_comment]
                        if not source[i]:
                            del source[i]
                        else:
                            i += 1
                    else:
                        del source[i]
                    continue
                else:
                    if in_beg_block_comment:
                        source[i] = source[i][:idx_beg_block_comment] + source[i][idx_end_block_commnet+2:]
                        if not source[i]:
                            del source[i]
                        else:
                            i += 1
                        break
                    else:
                        source[i] = source[i][idx_end_block_commnet+2:]
                        if not source[i]:
                            del source[i]
                        elif i > 0:
                            source[i-1] += source[i]
                            del source[i]
                        break

        beg_block_comment, end_block_commnet = '/*', '*/'
        line_comment = '//'
        i = 0
        while i < len(source):
            idx_line_commnet = source[i].find(line_comment)
            idx_beg_block_comment = source[i].find(beg_block_comment)

            # this line is not comment
            if idx_line_commnet == idx_beg_block_comment == -1:
                i += 1
                continue

            # this line is line comment
            if idx_line_commnet != -1 and (idx_beg_block_comment == -1 or idx_line_commnet < idx_beg_block_comment):
                do_line_comment(i, idx_line_commnet)
                continue

            # in block comment
            do_block_comment(i, idx_beg_block_comment)

        return source

def test(source, e):
    print('=== Source ===')
    print('\n'.join(source))
    r = Solution().removeComments(source)
    print('=== Correct? ===')
    print(r == e)
    print('=== Expect ===')
    print('\n'.join(e))
    print('=== Result ===')
    print('\n'.join(r))
    print('')


source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
e = ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
test(source, e)

source = ["a/*comment", "line", "more_comment*/b"]
e = ["ab"]
test(source, e)

source = ["  // variable declaration "]
e = ["  "]
test(source, e)
source = ["  /*// variable declaration*/ "]
e = ["   "]
test(source, e)
