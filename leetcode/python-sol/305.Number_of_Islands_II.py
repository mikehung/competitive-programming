class DisjointSet:
    def __init__(self, n):
        self.parent = [-1 for _ in range(n)]
        self.rank = [0 for _ in range(n)]
        self.num_groups = 0

    def find(self, x):
        if self.parent[x] != -1 and self.parent[x] != x:
            self.parent[x] = x
        return self.parent[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px != -1 and py != -1 and px != py:
            self.num_groups -= 1
            self.link(px, py)

    def link(self, x, y):
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def add(self, x):
        if self.find(x) == -1:
            self.parent[x] = x
            self.num_groups += 1

class Solution:
    def numIslands2(self, m, n, positions):
        def neighbors(x, y):
            for r, c in ((x+1, y), (x-1, y), (x, y+1), (x, y-1)):
                if 0 <= r < m and 0 <= c < n:
                    yield r, c

        def index(x, y):
            return x * n + y

        ds = DisjointSet(m*n)
        ans = []
        for x, y in positions:
            i = index(x, y)
            ds.add(i)
            for r, c in neighbors(x, y):
                ds.union(i, index(r, c))
            ans.append(ds.num_groups)
        print(ds.parent)
        return ans


m = n = 5
positions = [(0, 0), (2, 2), (4, 4), (0, 2), (0, 4), (4, 4), (2, 0), (2, 4), (1, 0), (0, 1), (1, 2), (2, 1), (1, 1)]
positions = [(0, 0), (1, 1), (0, 2), (0, 1)]
ans = [1, 2, 3, 4, 5, 5, 6, 7, 6, 5, 4, 4, 4]
print(Solution().numIslands2(m, n, positions))
