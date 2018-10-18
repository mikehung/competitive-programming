#!/usr/bin/env python

class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if length < 2 or k < 1:
            return 0

        p = [[[0 for _i in range(length)] for _j in range(length)] for _k in range(k)]

        for i in range(length):
            min_p = prices[i]

            p[0][i][i] = 0
            for j in range(i+1, length):
                if prices[j] > min_p:
                    p[0][i][j] = max(p[0][i][j-1], prices[j] - min_p)
                else:
                    min_p = prices[j]
                    p[0][i][j] = p[0][i][j-1]

        for l in range(1, k):
            for i in range(length):
                for j in range(i+1, length):
                    p[l][i][j] = p[l-1][i][j]
                    for m in range(i, j):
                        for n in range(l):
                            p[l][i][j] = max(p[l][i][j], p[n][i][m] + p[l-n-1][m][j])

        print(prices)
        for _ in p:
            for __ in _:
                print(__)
            print()
        print(p[k-1][0][len(prices)-1])
        return p[k-1][0][len(prices)-1]

s = Solution().maxProfit

# s(0,[1,2,1,5,1,3])
# s(1,[1,2,1,5,1,3])
# s(2,[1,2,1,5,1,3])
# s(3,[1,2,1,5,1,3])
# s(4,[1,2,1,5,1,3])
s(3,[2,6,8,7,8,7,9,4,1,2,4,5,8])
