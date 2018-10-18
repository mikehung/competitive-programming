class Solution:
    def strStr(self, s, p):
        m, n = len(s), len(p)
        if m < n:
            return -1
        P = 101
        D = 256  # number of chars
        K = pow(D, n-1) % P
        hs = hp = 0
        for i in range(n):
            hs = (hs*D + ord(s[i])) % P
            hp = (hp*D + ord(p[i])) % P
        for i in range(m-n+1):
            if hs == hp:
                for j in range(n):
                    if s[i+j] != p[j]:
                        break
                if j == n-1:
                    return i
            if i < m-n:
                hs = ((hs-ord(s[i])*K)*D + ord(s[i+n])) % P
        return -1

print(Solution().strStr('hello', 'll'))
print(Solution().strStr('', 'da'))
print(Solution().strStr('abidajflc', 'de'))
