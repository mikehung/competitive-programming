class Solution:
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        def dfs(u, unvisit, visiting, unsafe):
            unvisit.remove(u)
            visiting.add(u)
            for v in graph[u]:
                if v in unvisit:
                    dfs(v, unvisit, visiting, unsafe)
                elif v in visiting or v in unsafe:
                    unsafe |= visiting
            visiting.remove(u)

        n = len(graph)
        unvisit, visiting, unsafe = set([i for i in range(n)]), set(), set()
        while unvisit:
            u = unvisit.pop()
            unvisit.add(u)
            dfs(u, unvisit, visiting, unsafe)

        return sorted(set(range(n)) - unsafe)


graph = [[1,2],[2,3],[5],[0],[5],[],[]]
print(Solution().eventualSafeNodes(graph))

graph = [[0],[2,3,4],[3,4],[0,4],[]]
print(Solution().eventualSafeNodes(graph))
