# We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?
#
# Note that our partition must use every number in A, and that scores are not necessarily integers.

class Solution:
    def largestSumOfAverages(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: float
        """
        if K == 1:
            return sum(A)/len(A)
        if K == len(A):
            return sum(A)
        A = sorted(A)
        n = len(A)-K+1
        print(A[:n], A[n:])
        return sum(A[:n])/n+sum(A[n:])

A, K = [1,2,3,9,9], 3
print(Solution().largestSumOfAverages(A, K))

A, K = [1,2,3,9,9], 1
print(Solution().largestSumOfAverages(A, K))

A, K = [1,2,3,9,9], 5
print(Solution().largestSumOfAverages(A, K))

A, K = [4,1,7,5,6,2,3], 4
print(Solution().largestSumOfAverages(A, K))

# [1234567]
# 1234 5 6 7
