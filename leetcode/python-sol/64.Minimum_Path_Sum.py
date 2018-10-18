# Time: O(mn), m = len(grid), n = len(grid[0])
# Space: O(m)


class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0

        min_lst = [float('inf'), grid[0][0]]
        for num in grid[0][1:]:
            min_lst.append(min_lst[-1]+num)

        for row in grid[1:]:
            for i, num in enumerate(row, 1):
                min_lst[i] = num + min(min_lst[i-1], min_lst[i])

        return min_lst[-1]


grid = [[1,3,1], [1,5,1], [4,2,1]]
print(Solution().minPathSum(grid))
