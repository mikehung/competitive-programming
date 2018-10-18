class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        v, h = [0 for _ in range(m)], [0 for _ in range(n)]
        for r in range(m):
            for c in range(n):
                if grid[r][c] > v[r]:
                    v[r] = grid[r][c]
                if grid[r][c] > h[c]:
                    h[c] = grid[r][c]

        diff = 0
        for r in range(m):
            for c in range(n):
                diff += min(v[r], h[c]) - grid[r][c]

        return diff


grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
print(Solution().maxIncreaseKeepingSkyline(grid))
