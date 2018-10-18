# A = [1,3,5,4,6]
# B = [1,2,3,7,9]
#            ^
#      1 3 5 7 9
#      1 2 3 4 6
#
#      1 3 5 7 9
#      1 2 3 4 6
#
#      1 2 3 4 6
#      1 3 5 7 9
#
#      1 2 5 7 9
#      1 3 3 4 6
# change, can not change, nothing
class Solution:
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        def nSwap(a, b, i):
            if i == len(A):
                return 0
            if (a, b, i) not in memo:
                ans = float('inf')
                if a < A[i] and b < B[i]:
                    ans = nSwap(A[i], B[i], i+1)
                if A[i] != B[i] and a < B[i] and b < A[i]:
                    ans = min(ans, 1+nSwap(B[i], A[i], i+1))
                memo[a, b, i] = ans
            return memo[a, b, i]

        memo = {}
        return nSwap(float('-inf'), float('-inf'), 0)

A = [1,3,5,4,6]
B = [1,2,3,7,9]
print(Solution().minSwap(A, B))
