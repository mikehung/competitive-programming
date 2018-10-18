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
        def slove(row, ld, rd):
            if row == limit:
                self.ans += 1
                return

            pos = limit & ~(row | ld | rd)
            while pos:
                p = pos & (-pos)
                pos -= p
                slove(row+p, (ld+p)<<1, (rd+p)>>1)

        limit = (1 << n) - 1
        self.ans = 0
        slove(0, 0, 0)
        return self.ans


def test(n):
    beg = time.time()
    r = Solution().solveNQueens(n)
    print(n, r, time.time()-beg)


for i in range(33):
    test(i)
