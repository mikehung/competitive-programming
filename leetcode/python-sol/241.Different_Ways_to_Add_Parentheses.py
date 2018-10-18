#!/usr/bin/env python

class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        l, n = [], 0
        for c in input:
            if c.isdigit():
                n = n*10 + int(c)
            else:
                l, n = l+[n, c], 0
        l += [n]

sol = Solution().diffWaysToCompute('11+12*13-14')
