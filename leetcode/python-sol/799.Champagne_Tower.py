class Solution:
    def champagneTower(self, poured, query_row, query_glass):
        n = 101
        tower = [[0 for c in range(n)] for r in range(n)]
        tower[0][0] = poured
        for r in range(n-1):
            for c in range(r+1):
                if tower[r][c] > 1:
                    flow = (tower[r][c]-1)/2
                    tower[r+1][c] += flow
                    tower[r+1][c+1] += flow
                    tower[r][c] = 1
        return tower[query_row][query_glass]

Solution().champagneTower(35184000, 3, 4)
