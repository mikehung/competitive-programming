class Node:
    def __init__(self):
        self.bits = [None, None]


class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, nums):
        node = self.root
        bin_nums = bin(nums)[2:].zfill(32)
        for b in map(int, bin_nums):
            if node.bits[b] is None:
                node.bits[b] = Node()
            node = node.bits[b]

    def findMax(self):
        def compute(n, node1, node2):
            if node1 is None and node2 is None:
                return n
            if node1 is None:
                return compute(2*n, node2.bits[0], node2.bits[1])
            if node2 is None:
                return compute(2*n, node1.bits[0], node1.bits[1])
            return max([compute(2*n+1, node1.bits[0], node2.bits[1]),
                        compute(2*n+1, node2.bits[0], node1.bits[1]),
                        compute(2*n, node1.bits[0], node1.bits[1]),
                        compute(2*n, node2.bits[0], node1.bits[1])])

        return compute(0, self.root.bits[0], self.root.bits[1])


class Solution:
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        trie = Trie()
        for num in nums:
            trie.add(num)
        return trie.findMax()

nums = [3, 10, 5, 25, 2, 8]
print(Solution().findMaximumXOR(nums))
