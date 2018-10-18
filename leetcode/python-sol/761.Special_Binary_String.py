class Solution:
    def makeLargestSpecial(self, S):
        """
        :type S: str
        :rtype: str
        """




def test(S, A):
    ans = Solution().makeLargestSpecial(S)
    print(ans)


S = '11001100'
A = '11110000'
test(S, A)

S = '110100'
A = '110100'
test(S, A)

S = '101100'
A = '110010'
test(S, A)
