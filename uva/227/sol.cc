#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N = 5;
char puzzle[N][N];

int main()
{
    char _;
    int x, y, t = 0;
    while (true) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                scanf("%c", &puzzle[r][c]);
                if (puzzle[r][c] == 'Z') return 0;
                if (puzzle[r][c] == ' ')
                    x = r, y = c;
            }
            scanf("%c", &_);
        }
        char act;
        vector<char> actions;
        while (scanf("%c", &act) == 1 && act != '0')
            if (act != '\n')
                actions.push_back(act);
        scanf("%c", &_);
        bool flag = true;
        for (char act: actions) {
            fprintf(stderr, "act: %c\n", act);
            if (act == 'A') {
                if (x-1 < 0) {
                    flag = false;
                    break;
                }
                puzzle[x][y] = puzzle[x-1][y];
                x--;
            } else if (act == 'B') {
                if (x+1 >= N) {
                    flag = false;
                    break;
                }
                puzzle[x][y] = puzzle[x+1][y];
                x++;
            } else if (act == 'R') {
                if (y+1 >= N) {
                    flag = false;
                    break;
                }
                puzzle[x][y] = puzzle[x][y+1];
                y++;
            } else if (act == 'L') {
                if (y-1 < 0) {
                    flag = false;
                    break;
                }
                puzzle[x][y] = puzzle[x][y-1];
                y--;
            }
        }
        if (t) printf("\n");
        printf("Puzzle #%d:\n", ++t);
        if (!flag) {
            printf("This puzzle has no final configuration.\n");
        } else {
            puzzle[x][y] = ' ';
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (c) printf(" ");
                    printf("%c", puzzle[r][c]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
