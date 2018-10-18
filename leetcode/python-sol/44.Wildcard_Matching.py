class Solution:
    def isMatch(self, s, p):
        sl, pl = len(s)+1, len(p)+1
        dp = [[False for j in range(sl)] for i in range(pl)]
        dp[0][0] = True
        for i in range(1, pl):
            if p[i-1] == '*':
                dp[i][0] = True
            else:
                break
        for i in range(1, pl):
            for j in range(1, sl):
                if p[i-1] != '*':
                    dp[i][j] = dp[i-1][j-1] and (p[i-1] == s[j-1] or p[i-1] == '?')
                else:
                    dp[i][j] = dp[i-1][j-1] or dp[i][j-1] or dp[i-1][j]
        print(dp)
        return dp[-1][-1]

Solution().isMatch('ab', '*a')
Solution().isMatch('ab', '*b')
