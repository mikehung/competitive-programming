class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if A == B:
            return False
        if len(A) != len(B):
            return False
        return (A*2).find(B) != -1


print(Solution().rotateString('abcde', 'bcdea'))
print(Solution().rotateString('abcde', 'cdeab'))
print(Solution().rotateString('abcde', 'adeab'))
print(Solution().rotateString('abcde', 'abcde'))
