class Node:
    def __init__(self):
        self.word = None
        self.dic = {}
        self.weight = []

    def __str__(self):
        return 'dic: {}\nword: {}\nweight: {}'.format(self.dic.keys(), self.word, self.weight)


# How to add empty root?
class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, word, weight):
        node = self.root
        for c in word:
            if c not in node.dic:
                node.dic[c] = Node()
            node.weight.append(weight)
            node = node.dic[c]
        node.word = word
        node.weight.append(weight)

    def dump(self):
        stack = [self.root]
        while stack:
            node = stack.pop()
            print(node)
            for c, n in node.dic.items():
                stack.append(n)


trie = Trie()
trie.add('apple', 0)
trie.add('apr', 1)
trie.add('cde', 2)
trie.add('cdce', 3)
trie.dump()


# Time:
 # __init__: O(WK**3), W = len(words), K = max(map(len, words))
 # f: O(1)
# Space: # O(K**2)
class WordFilter:
    def __init__(self, words):
        self.prefix_trie = Trie()
        self.suffix_trie = Trie()
        for weight, word in enumerate(words):
            self.prefix_trie.add(word, weight)
            self.suffix_trie.add(list(reversed(word)), weight)

    def f(self, prefix, suffix):
        prefix_node = self.prefix_trie
        suffix_node = self.suffix_trie
        for c in prefix:
            pass


class WordFilter:
    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.prefix_suffix = {}
        for weight, word in enumerate(words):
            for i in range(len(word)+1):
                prefix = word[:i]
                for j in range(len(word)+1):
                    self.prefix_suffix[(prefix, word[j:])] = weight


    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        return self.prefix_suffix.get((prefix, suffix), -1)



# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
wf = WordFilter(['apple', 'gge', 'abced'])
def test(prefix, suffix, e):
    r = wf.f(prefix, suffix)
    # print(e == r, prefix, suffix, e, r)

test('a', '', 2)
test('a', 'e', 0)
test('ab', 'e', -1)
test('', 'e', 1)
test('g', 'gge', 1)
test('gg', 'gge', 1)
test('gge', 'gge', 1)
