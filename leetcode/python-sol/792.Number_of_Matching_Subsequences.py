import collections
from bisect import bisect_left


class Solution:
    def numMatchingSubseq(self, S, words):
        def check(word, ndic):
            si = 0
            for c in word:
                if c not in ndic:
                    return False
                lst, ci = ndic[c]
                ci = bisect_left(lst, si, lo=ci)
                if ci >= len(lst):
                    return False
                si = lst[ci]+1
                ndic[c][1] = ci+1
            return True

        dic = collections.defaultdict(list)
        for i, c in enumerate(S):
            dic[c].append(i)

        count = 0
        ndic = {k: [v, 0] for k, v in dic.items()}
        for word in words:
            if check(word, ndic):
                count += 1
            for k in ndic:
                ndic[k][1] = 0
        return count




S = 'abca'
words = ['aa', 'bc', 'ba', 'ca', 'cb']
S = "abcde"
words = ["a", "bb", "acd", "ace"]
print(Solution().numMatchingSubseq(S, words))
# a: [0, 3]
# b: [1]
# c: [2]
