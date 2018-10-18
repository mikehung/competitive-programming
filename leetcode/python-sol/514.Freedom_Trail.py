import collections


class Solution:
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        dic = collections.defaultdict(list)
        for i, c in enumerate(ring):
            dic[c].append(i)
        n = len(ring)
        lst = [(0, 0)]
        for c in key:
            nxt_lst = []
            for v in dic[c]:
                min_step = float('inf')
                for step, u in lst:
                    step += min((v-u)%n, (u-v)%n)
                    if step < min_step:
                        min_step = step
                nxt_lst.append((min_step+1, v))
            lst = nxt_lst
        return min(lst)[0]


def test(ring, key):
    print(ring, key)
    r = Solution().findRotateSteps(ring, key)
    print(r)


ring = 'GODDING'
key = 'GD'
test(ring, key)
ring = 'ABRRCBD'
key = 'BCD'
test(ring, key)
