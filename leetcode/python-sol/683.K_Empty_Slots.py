#!/usr/bin/env python

class Solution(object):
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        class BITree(object):
            def __init__(self, l):
                self.bit_tree = [0 for i in range(0, len(l)+1)]

            def update(self, index, value):
                while index < len(self.bit_tree):
                    self.bit_tree[index] += value
                    index += index & (-index)

            def read(self, index):
                result = 0
                while index > 0:
                    result += self.bit_tree[index]
                    index -= index & (-index)
                return result

            def get(self, index):
                try:
                    return self.read(index) - self.read(index-1)
                except IndexError:
                    return None

        bit_tree = BITree(flowers)
        space = k + 1
        for day, flower in enumerate(flowers):
            bit_tree.update(flower, 1)
            if bit_tree.get(flower - space) == 1 and bit_tree.read(flower - space) == bit_tree.read(flower - 1):
                return day + 1
            if bit_tree.get(flower + space) == 1 and bit_tree.read(flower + space - 1) == bit_tree.read(flower):
                return day + 1

        return -1


def test(flowers, k, expect):
    result = Solution().kEmptySlots(flowers, k)
    print(expect == result, flowers, k, expect, result)

test([1,3,2], 1, 2)
test([1,2,3], 1, -1)
