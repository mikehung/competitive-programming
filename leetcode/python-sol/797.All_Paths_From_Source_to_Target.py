class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        def dfs(u, ans, path):
            if u == n-1:
                ans.append(path)
            else:
                for v in graph[u]:
                    dfs(v, ans, path + [v])


        n = len(graph)
        ans = []
        path = [0]
        dfs(0, ans, path)
        return ans


graph = [[1,2,3,4], [3], [3], [4], []]
ans = [[0,1,3],[0,2,3]]
print(Solution().allPathsSourceTarget(graph))
