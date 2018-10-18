import collections

import itertools
class Solution:
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        def helper(count):
            key = tuple(count.items())
            if not count:
                return 0

            if key not in memo:
                min_stickers = float('inf')
                for s_count, s_set in stickers:
                    if s_set & set(count.keys()):
                        c = count - s_count
                        strip(c)
                        num_stickers = helper(c)
                        if 1 + num_stickers < min_stickers:
                            min_stickers = 1 + num_stickers
                memo[key] = min_stickers
            return memo[key]

        def strip(count):
            for k, v in count.items():
                if v <= 0:
                    del count[k]

        if not target:
            return 0
        if set(target) - set(itertools.chain.from_iterable(stickers)):
            return -1

        stks = []
        for s in stickers:
            for s_count,
        stks = {}
        for s in stickers:
            s_set = frozenset(s)
            if s_set not in stks:
                stks[s_set] = [collections.Counter(s)]
            else:
                lst = []
                cnt = collections.Counter(s)
                for c in stks[s_set]:
                    if (c - cnt).elements():
                        lst.append(c)
                if not lst or (cnt - lst[0]).elements():
                    lst.append(cnt)
                stks[s_set] = lst

        print(stks)
        return
        ans = 0
        memo = {}
        count = collections.Counter(target)
        stickers = [(collections.Counter(s), set(s)) for s in stickers]
        helper(count)
        return memo[tuple(count.items())]

print(Solution().minStickers(["with", "example", "science"], "thehat"))
print(Solution().minStickers(["notice", "possible"], "basicbasic"))
stickers=["sail","just","point","over","hard","share","say","distant","proper","occur","before","whose","guess","lead","prove","pattern","six","fat","add","music","grand","show","final","hope","listen","week","picture","buy","run","though","between","serve","here","nation","forward","stick","decide","post","ear","than","he","word","would","band","many","well","gun","wish","toward","think"]
target="governgreat"
print(Solution().minStickers(stickers, target))
