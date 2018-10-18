# Analysis:
#  Time: O(n*?)
class Solution:
    def splitArraySameAverage(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        def find(target, i, cnt):
            if cnt == 0 and target == 0:
                return True
            if i == len(A) or cnt == 0 or target == 0:
                return False
            if (target, i, cnt) in not_found:
                return False
            ret = False
            if find(target, i+1, cnt):
                ret = True
            if not ret and A[i] <= target:
                ret = find(target-A[i], i+1, cnt-1)
            if not ret:
                not_found.add((target, i, cnt))
            return ret

        n, s = len(A), sum(A)
        not_found = set()
        for i in range(1, n//2+1):
            if i*s % n == 0 and find(i*s//n, 0, i):
                return True
        return False


A = range(1, 9)
print(Solution().splitArraySameAverage(A))
