class Solution:
    def countSmaller(self, nums):
        def sort(enum):
            mid = len(enum)//2
            if mid:
                left, right = sort(enum[:mid]), sort(enum[mid:])
                for i in range(len(enum))[::-1]:
                    if not right or (left and left[-1][1] > right[-1][1]):
                        less[left[-1][0]] += len(right)
                        enum[i] = left.pop()
                    else:
                        enum[i] = right.pop()
            return enum

        less = [0] * len(nums)
        sort(list(enumerate(nums)))
        return less


class BITree:
    def __init__(self, n):
        self.tree = [0] * (n+1)

    def getsum(self, i):
        ret = 0
        i += 1
        while i > 0:
            ret += self.tree[i]
            i -= i & -i
        return ret

    def update(self, i, v):
        i += 1
        while i < len(self.tree):
            self.tree[i] += v
            i += i & -i


class Solution2:
    def countSmaller(self, nums):
        rank = {v: i for i, v in enumerate(sorted(set(nums)))}
        bitree = BITree(len(rank))
        ans = [0]*len(nums)
        for i, v in list(enumerate(nums))[::-1]:
            ans[i] = bitree.getsum(rank[v]-1)
            bitree.update(rank[v], 1)
        return ans


class BSTNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.cnt = 1
        self.left_cnt = 0


nums = [5, 8, 5, 6, 1]
ans = [1, 3, 1, 1, 0]
print(nums, Solution().countSmaller(nums), ans)
print(nums, Solution2().countSmaller(nums), ans)
