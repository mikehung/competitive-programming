import time
from copy import copy, deepcopy


class Solution:
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        def get_answers(n):
            mask = ['0']*(n+1)
            mask[::2] = ['1']*((n+2)//2)
            one, zero = mask[:n], mask[1:n+1]
            flag = True
            board = []
            for _ in range(n+1):
                board.append(copy(one) if flag else copy(zero))
                flag = False if flag else True

            b0, b1 = deepcopy(board[:n]), deepcopy(board[1:])
            s0, s1 = b2s(b0), b2s(b1)
            return set([s0, s1]), [b0, b1]

        def b2s(b):
            l = []
            for row in b:
                l.extend(row)
            return ''.join(l)

        def swap_row(b, i, j):
            nb = deepcopy(b)
            nb[i], nb[j] = nb[j], nb[i]
            return nb

        def swap_col(b, i, j):
            nb = deepcopy(b)
            for _ in range(n):
                nb[_][i], nb[_][j] = nb[_][j], nb[_][i]
            return nb

        n = len(board)
        step = 0
        seen = set()

        b = []
        for row in board:
            b.append([str(_) for _ in row])
        s = b2s(b)
        if abs(s.count('0')-s.count('1')) != n%2:
            return -1

        beg_set, beg_boards = set([s]), [b]
        end_set, end_boards = get_answers(n)
        if beg_set & end_set:
            return step

        seen.update(beg_set)
        seen.update(end_set)

        while beg_boards:
            step += 1

            if len(beg_set) > len(end_set):
                beg_set, end_set = end_set, beg_set
                beg_boards, end_boards = end_boards, beg_boards

            new_set, new_boards = set(), []
            for b in beg_boards:
                for i in range(n):
                    for j in range(i+1, n):
                        for fn in (swap_row, swap_col):
                            new_b = fn(b, i, j)
                            new_s = b2s(new_b)
                            if new_s in end_set:
                                return step
                            if new_s not in seen:
                                seen.add(new_s)
                                new_set.add(new_s)
                                new_boards.append(new_b)
            beg_set, beg_boards = new_set, new_boards

        return -1

board =[[1, 0], [0, 1]]
print(Solution().movesToChessboard(board))
board =[[0, 1], [1, 0]]
print(Solution().movesToChessboard(board))
board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
print(Solution().movesToChessboard(board))
board = [[1,0,1,0,1],[1,0,1,0,1],[0,1,0,1,0],[0,1,0,1,0],[0,1,0,1,0]]
print(Solution().movesToChessboard(board))
board = [[1,0,1,1,0],[1,0,1,1,0],[1,1,0,0,1],[1,1,0,0,1], [1,1,0,0,1]]
print(Solution().movesToChessboard(board))
board = [[1, 0], [1, 0]]
print(Solution().movesToChessboard(board))
board = [[1,1,1,0,0,1,0,0],[0,0,0,1,1,0,1,1],[1,1,1,0,0,1,0,0],[0,0,0,1,1,0,1,1],[0,0,0,1,1,0,1,1],[0,0,0,1,1,0,1,1],[1,1,1,0,0,1,0,0],[1,1,1,0,0,1,0,0]]
t = time.time()
print(Solution().movesToChessboard(board))
print(time.time()-t)
board = [[0, 1, 1], [0, 1, 1], [1, 0, 0]]
print(Solution().movesToChessboard(board))
