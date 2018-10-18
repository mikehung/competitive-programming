class DS:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0 for _ in range(n)]

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        elif self.rank[py] < self.rank[px]:
            self.parent[py] = px
        else:
            self.parent[py] = px
            self.rank[px] += 1

def Union(ds, x, y):
    print('union {}, {}'.format(x, y))
    ds.union(x, y)
    print(ds.parent, ds.rank)

def Find(ds, x):
    print('find {}'.format(x))
    print(ds.find(x), ds.parent)


ds = DS(5)
Union(ds, 1, 2)
Find(ds, 1)
Find(ds, 2)
Union(ds, 1, 2)
Union(ds, 3, 4)
Find(ds, 3)
Find(ds, 4)
Union(ds, 2, 3)
Find(ds, 0)
Find(ds, 1)
Find(ds, 4)
