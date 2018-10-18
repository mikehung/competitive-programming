#!/usr/bin/env python

import copy
import pprint
import time


class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def is_safe(board, i, row):
            if any([board[r] == i for r in range(n) if board[r] != -1]):
                return False
            if any([abs(r-row) == abs(board[r]-i) for r in range(n) if board[r] != -1]):
                return False
            return True

        def helper(board, result, row):
            if row == n:
                result.append(['.'*i+'Q'+'.'*(n-i-1) for i in board])
            for i in range(n):
                if is_safe(board, i, row):
                    board[row] = i
                    helper(board, result, row+1)
                    board[row] = -1

        result = []
        board = [-1] * n
        helper(board, result, 0)
        return result


def test(n):
    beg = time.time()
    r = Solution().solveNQueens(n)
    pprint.pprint(r)
    print(n, len(r), time.time()-beg)

test(4)
test(8)
# for i in range(10):
#     test(i)
